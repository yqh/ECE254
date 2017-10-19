SET PATH=C:\Keil\ARM\ARMCC\bin\;C:\ProgramData\Oracle\Java\javapath;C:\Program Files (x86)\Lenovo\FusionEngine;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Lenovo\Bluetooth Software\;C:\Program Files\Lenovo\Bluetooth Software\syswow64;C:\Program Files (x86)\Lenovo\Motion Control\;C:\Program Files (x86)\Common Files\lenovo\easyplussdk\bin;C:\Program Files (x86)\Skype\Phone\;C:\Program Files\OpenVPN\bin;C:\Program Files\Git\cmd;C:\Program Files\PuTTY\;C:\Ruby23-x64\bin;C:\Users\Ben\AppData\Local\Microsoft\WindowsApps;C:\Program Files (x86)\SSH Communications Security\SSH Secure Shell;C:\Users\Ben\AppData\Local\atom\bin
SET CPU_TYPE=Cortex-M3
SET CPU_VENDOR=ARM
SET UV2_TARGET=CM3_LE
SET CPU_CLOCK=0x00B71B00
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_task.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_system.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_event.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_list.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_mailbox.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_semaphore.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_time.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_timer.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_mutex.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_robin.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_membox.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_task_ext.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_membox_ext.__i"
"C:\Keil\ARM\ARMCC\bin\ArmAsm" --Via ".\cm3_le\svc_table._ia"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\hal_cm3.__i"
"C:\Keil\ARM\ARMCC\bin\ArmAr" --Via "ArInp.Scr"
cmd.exe /C copy ArInp.Scr CM3_LE\BuildLib.scr
