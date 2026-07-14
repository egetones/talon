# talon
Talon — Kernel-level mini EDR detecting DKOM hidden modules, syscall table hooks, ptrace injection, and C2 beacon patterns via kallsyms + kprobes + netlink. Built as the defensive counterpart to Titan-Rootkit, Needle, and Vortex-C2.

Build:
sudo dnf install -y kernel-devel-$(uname -r) kernel-headers-$(uname -r)
make
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
Test:
make load
make check     # /proc/talon çıktısı + dmesg logu görünmeli
make unload
