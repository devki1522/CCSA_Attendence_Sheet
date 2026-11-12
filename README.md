# CyberCheck 🎯

A lightweight, high-performance event attendance tracking web service designed for student clubs and campus events. Built with modern C++20, Crow, SQLite, and Dockerized for easy deployment.

---

## 🚀 Features

- **High-Performance Backend:** Asynchronous REST API powered by modern C++20 and the Crow microframework.
- **Embedded Storage:** Zero-configuration ACID compliance using embedded SQLite.
- **Responsive Web UI:** Clean, mobile-friendly attendee check-in and administrative views.
- **Containerized Deployment:** Multi-stage Docker container ready for server hosting.

---

## 🛠 Tech Stack

| Component | Technology |
|---|---|
| **Language** | C++20 |
| **HTTP Framework** | [CrowCpp](https://crowcpp.org/) |
| **Database** | SQLite3 |
| **Frontend** | HTML5, CSS3, JavaScript |
| **Build System** | CMake (v3.20+) |
| **Package Manager** | vcpkg |
| **Deployment** | Docker |

---

## 📁 Project Structure

```text
CyberCheck/
├── CMakeLists.txt      # Build configuration
├── src/                # C++ source files
├── include/            # Header files (.hpp)
├── public/             # Static frontend assets (HTML, CSS, JS)
├── database/           # SQLite database schema and local DB
├── tests/              # Unit & integration tests
└── Dockerfile          # Container configuration
```

## Run with Docker

Install and start Docker Desktop, then run this from the project folder:

```powershell
docker compose up --build
```

The first run builds the Linux image and starts the service on port `27000`.
Open <http://localhost:27000> to check that it is running. Stop it with
`Ctrl+C`; use `docker compose down` to remove the stopped container.

The image compiles the C++ service inside Linux, so a Windows `g++` install is
not needed. Crow's Asio headers and SQLite development files are installed in
the build stage. The `database` folder is mounted for persistent database
files when database support is added to the service.
