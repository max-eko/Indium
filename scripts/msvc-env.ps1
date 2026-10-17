# Finds the Visual Studio installation path portably
$vswhere = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"

$vsPath = & $vswhere -latest -products '*' `
    -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
    -property installationPath

if (-not $vsPath) {
    Write-Error "Visual Studio C++ Build Tools not found!"
    exit 1
}

# Gets the environment variables from vcvarsall.bat
$vcvars = Join-Path $vsPath "VC\Auxiliary\Build\vcvarsall.bat"

if (-not (Test-Path -LiteralPath $vcvars)) {
    Write-Error "vcvarsall.bat not found: $vcvars"
    exit 1
}

$envCmd = "call `"$vcvars`" x64 >nul && set"
$envVars = & $env:ComSpec /d /c $envCmd

if ($LASTEXITCODE -ne 0) {
    Write-Error "Failed to initialize the MSVC environment."
    exit 1
}

# Injects MSVC and Windows SDK variables into the current terminal session
foreach ($line in $envVars) {
    if ($line -match '^([^=]+)=(.*)$') {
        [System.Environment]::SetEnvironmentVariable(
            $Matches[1],
            $Matches[2],
            [System.EnvironmentVariableTarget]::Process
        )
    }
}

# Deletes the build directory to clear the build cache
if (Test-Path -LiteralPath "build") {
    Remove-Item -Recurse -Force "build"
}
mkdir build