$remoteComputer = Read-Host "Enter the target computer name" 

$parentKeyPath = 'HKLM:\SOFTWARE\Policies\Adobe\Adobe Acrobat\DC\FeatureLockDown\cSecurity'
$childKeyPath = 'HKLM:\SOFTWARE\Policies\Adobe\Adobe Acrobat\DC\FeatureLockDown\cSecurity\cPubSec'

$newDWORDs = @{
    "bEnableCEFBasedUI" = 0 
    "bSelfSignCertGen" = 0
}

Enable-PSRemoting -Force

Invoke-Command -ComputerName $remoteComputer -ScriptBlock {
    param($parentKeyPath, $childKeyPath, $newDWORDs)

    if (-not (Test-Path -Path $parentKeyPath)) {
        New-Item -Path $parentKeyPath -Force
    }

    if (-not(Test-Path -Path $childKeyPath)) {
        New-Item -Path $childKeyPath -Force
    }

    foreach ($name in $newDWORDs.Keys) {
        Set-ItemProperty -Path $childKeyPath -Name $name -Value $newDWORDs[$name] -Type DWord
    }

} -ArgumentList $parentKeyPath, $childKeyPath, $newDWORDs