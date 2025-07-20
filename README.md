📝 Project Overview
NetWatch CLI is a lightweight command-line interface (CLI) tool developed in C for Linux environments. It enables users to monitor and manage key networking aspects of their system directly through the terminal. Designed for system administrators, developers, and power users, this utility offers real-time insights into Ethernet connection status, port activity, data speeds, and internet control.

🛠️ Core Features
- Ethernet Interface Monitoring
- Detects active Ethernet connections
- Displays assigned IP addresses and link status (UP/DOWN)
- Port-Based Data Speed Tracker
- Monitors incoming and outgoing data rates
- Tracks activity on user-specified ports
- Presents traffic stats in human-readable format (e.g. Mbps/Kbps)
- Port Control Manager
- Lists all open and active ports on the system's IP
- Allows users to deactivate/reactivate specific ports via iptables or firewall utilities
- Helps enhance system security by managing port access
- Internet Service Toggle
- Provides control to disable or enable internet access on demand
- Uses firewall rules or network interface manipulation to cut off external connectivity

⚙️ Technologies & Tools
- Programming Language: C
- Dependencies: Linux system utilities (e.g. netstat, ifconfig/ip, iptables, tc, ss)
- Environment: Tested on Debian-based and Red Hat-based distributions

📦 Project Benefits
- Real-time control over system networking
- Helps isolate suspicious activity on ports
- Improves security posture by enabling on-demand internet shutdown
- Lightweight utility with minimal dependencies
