# STM32 Lab 2 — Timer & Software Timer

> HCMUT Microprocessors–Microcontrollers (HK241), Lab 2 — bài tập ex1–ex9 trên STM32F100C6Tx: GPIO, hardware timer, software timer, 7‑segment scanning và clock display.

## Project scope

| Folder | Nội dung |
|---|---|
| `ex1/` | LED blink với software timer |
| `ex2/` | Multi-rate LED blink |
| `ex3_4/` | Button polling + debounce |
| `ex5_7/` | 7‑segment scan + button control |
| `ex5_8/` | Mở rộng ex5–7 thêm `updateClockBuffer` |
| `ex8/`  | Proteus-only: phiên bản tinh chỉnh của ex8 |
| `ex9/`  | Digital clock đầy đủ (HH:MM:SS) |
| `sandbox/` | Reference projects: `led_blinky`, `timer_interrupt` |
| `docs/` | Tài liệu yêu cầu (PDF) + video demo Proteus |

Mỗi exN có 2 thư mục con:
- `stm32/` — STM32CubeIDE project (mở thẳng bằng STM32CubeIDE → Import existing project)
- `proteus/` — file `.pdsprj` để mô phỏng

## Hardware / Toolchain

| Item | Version / spec |
|---|---|
| MCU | STM32F100C6Tx (Cortex‑M3, 24 MHz) |
| IDE | STM32CubeIDE ≥ 1.13 (sử dụng GCC arm-none-eabi đi kèm) |
| HAL | STM32Cube F1 (HAL driver bundled trong từng exN) |
| Simulator | Proteus 8 Professional |
| OS test | Windows 10/11 |

## Build & flash

1. Mở STM32CubeIDE → **File ▸ Import ▸ Existing Projects into Workspace**.
2. Trỏ đến thư mục `exN/stm32/`. Mỗi exN là một project độc lập.
3. **Project ▸ Build All** (`Ctrl+B`). Output `.elf` / `.hex` sinh trong `exN/stm32/Debug/` (đã được `.gitignore`).
4. Mô phỏng: mở `exN/proteus/Lab2_exN.pdsprj` bằng Proteus, nạp file `.hex` vào MCU model, **Play**.
5. Nạp lên board thật: dùng ST‑LINK ▸ **Run** từ STM32CubeIDE.

## Team

| Họ tên | MSSV | Vai trò |
|---|---|---|
| _TBD_ | _TBD_ | _TBD_ |
| _TBD_ | _TBD_ | _TBD_ |

## Reports & references

- 📄 [`docs/requirement.pdf`](docs/requirement.pdf) — đề bài chính thức (Lab 2 Timer)
- 🎬 [`docs/videos/ex9_demo.mp4`](docs/videos/ex9_demo.mp4) — demo Proteus của ex9 (digital clock)

## License

Code sample của STMicroelectronics tuân theo license đi kèm trong từng file (`Copyright (c) 2024 STMicroelectronics`). Code do nhóm viết để học tập, không có license thương mại.
