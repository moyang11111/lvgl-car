# LVGL 车载仪表盘

基于 LVGL (Light and Versatile Graphics Library) 的 Linux 车载仪表盘系统。

## 项目简介

本项目在 LVGL Linux 移植的基础上，开发了一套车载仪表盘人机交互界面（HMI），包含：
- 🚗 **仪表盘屏幕** — 速度表、转速表、油量显示
- 🔄 **转向灯控制** — 左右转动画效果
- 📹 **视频播放模块** — 车载娱乐屏
- 🎚️ **弧形进度条** — 动态弧形仪表控件
- 🖥️ **多屏幕切换** — 4 个独立 UI 屏幕

## 技术栈

- **GUI 框架**: LVGL v9.x (Light and Versatile Graphics Library)
- **平台**: Linux (支持 Framebuffer / DRM / SDL / X11 / Wayland)
- **语言**: C
- **构建**: CMake / GNU Make
- **输入**: evdev (触摸屏/鼠标)

## 快速开始

```bash
# 克隆项目（含 submodule）
git clone --recursive https://github.com/YOUR_USERNAME/lvgl-car-dashboard.git
cd lvgl-car-dashboard

# 安装依赖（以 Ubuntu 为例）
sudo apt install build-essential cmake libsdl2-dev

# 编译
cmake -B build -S .
make -C build -j

# 运行
./build/bin/lvglsim
```

## 目录结构

```
├── src/
│   ├── main.c                    # 主程序入口
│   ├── account.c/h               # 账户管理模块
│   ├── video_play.c/h            # 视频播放模块
│   ├── ui_turn_signal.c/h        # 转向灯模块
│   ├── ui_arc_auto_decrease.c/h  # 弧形仪表模块
│   ├── UI/                       # SquareLine Studio 生成的 UI
│   │   ├── ui.c/h
│   │   ├── screens/              # 4 个屏幕
│   │   ├── images/               # UI 图片资源
│   │   ├── fonts/                # 字体文件
│   │   └── components/           # UI 组件
│   └── lib/                      # 驱动后端（显示/输入）
├── lv_conf.h                     # LVGL 配置
├── CMakeLists.txt                # 构建配置
├── lvgl/                         # LVGL 库（git submodule）
└── Makefile                      # GNU Make 构建
```

## 许可证

本项目基于 [lv_port_linux](https://github.com/lvgl/lv_port_linux) 开发，LVGL 库使用 MIT 许可证。
