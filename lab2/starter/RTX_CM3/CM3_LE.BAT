SET PATH=C:\opt\Keilv460\ARM\ARMCC\bin\;C:\ProgramData\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\ThinkPad\Bluetooth Software\;C:\Program Files\ThinkPad\Bluetooth Software\syswow64;C:\Program Files\MiKTeX 2.9\miktex\bin\x64\;C:\Program Files (x86)\Calibre2\;C:\Program Files (x86)\SSH Communications Security\SSH Secure Shell
SET CPU_TYPE=Cortex-M3
SET CPU_VENDOR=ARM
SET UV2_TARGET=CM3_LE
SET CPU_CLOCK=0x00B71B00
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_task.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_system.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_event.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_list.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_mailbox.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_semaphore.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_time.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_timer.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_mutex.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_robin.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_membox.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_task_ext.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\rt_membox_ext.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmAsm" --Via ".\cm3_le\svc_table._ia"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmCC" --Via ".\cm3_le\hal_cm3.__i"
"C:\opt\Keilv460\ARM\ARMCC\bin\ArmAr" --Via "ArInp.Scr"
cmd.exe /C copy ArInp.Scr CM3_LE\BuildLib.scr
