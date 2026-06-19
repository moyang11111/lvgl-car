# LVGL 车载仪表盘

基于 LVGL + GEC6818 嵌入式 Linux 开发板的车载仪表盘人机交互系统（HMI）。

## 项目简介

在 GEC6818 平台上，使用 LVGL 图形库开发了一套车载仪表盘界面，包含：
- 🚗 **仪表盘屏幕** — 速度表、转速表、安全带/刹车状态
- 🔄 **转向灯动画** — 左右转动态指示
- 📹 **视频播放** — 基于 mplayer 后台解码 + LVGL 渲染
- 🎚️ **弧形进度条** — 动态转速/速度弧形控件
- 🖥️ **4 屏切换** — 仪表、娱乐、设置、导航多屏交互

## 硬件平台

- **主控**: GEC6818（ARM Cortex-A53）
- **屏幕**: 800 × 480 LCD
- **系统**: Linux（Framebuffer / SDL）

## 技术栈

- **GUI**: LVGL v9.4
- **语言**: C
- **视频**: mplayer（后台解码，LVGL 渲染画面）
- **构建**: CMake
- **输入**: evdev（触摸屏）
- **UI 工具**: SquareLine Studio

## 快速开始

```bash
# 克隆（含 LVGL 子模块）
git clone --recursive https://github.com/moyang11111/lvgl-car.git
cd lvgl-car

# 安装依赖
sudo apt install build-essential cmake libsdl2-dev mplayer

# 编译
cmake -B build -S .
make -C build -j

# 运行
./build/bin/lvglsim
```

## 目录结构

```
├── src/
│   ├── main.c                    # 入口
│   ├── video_play.c/h            # mplayer 视频播放模块
│   ├── ui_turn_signal.c/h        # 转向灯
│   ├── ui_arc_auto_decrease.c/h  # 弧形仪表
│   ├── account.c/h               # 账户管理
│   ├── UI/                       # SquareLine Studio 导出
│   │   ├── ui.c/h
│   │   ├── screens/              # Screen1~4
│   │   ├── images/               # 图片资源
│   │   ├── fonts/                # 字体
│   │   └── components/           # UI 组件
│   └── lib/                      # 显示/输入驱动后端
├── lv_conf.h                     # LVGL 配置（800×480）
├── CMakeLists.txt
├── lvgl/                         # LVGL 库（git submodule）
└── docker/                       # CI 构建环境
```

## 许可证

本项目基于 [lv_port_linux](https://github.com/lvgl/lv_port_linux)，LVGL 使用 MIT 许可证。
