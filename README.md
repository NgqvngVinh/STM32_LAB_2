# STM32 Lab 2 — Timer & Software Timer

> HCMUT Microprocessors–Microcontrollers (HK241), Lab 2 — exercises ex1–ex9 on STM32F100C6Tx: GPIO, hardware timer, software timer, 7‑segment scanning and clock display.

## Project scope

| Folder | Content |
|---|---|
| `ex1/` | LED blink driven by a software timer |
| `ex2/` | Multi-rate LED blink |
| `ex3_4/` | Button polling + debounce |
| `ex5_7/` | 7‑segment scan + button control |
| `ex5_8/` | Extends ex5–7 with `updateClockBuffer` |
| `ex8/`  | Proteus-only: refined variant of ex8 |
| `ex9/`  | Full digital clock (HH:MM:SS) |
| `sandbox/` | Reference projects: `led_blinky`, `timer_interrupt` |
| `docs/` | Lab requirement (PDF) + Proteus demo video |

Each `exN/` ships with two subfolders:
- `stm32/` — STM32CubeIDE project (open via *Import existing project*)
- `proteus/` — `.pdsprj` for simulation

## Hardware / Toolchain

| Item | Version / spec |
|---|---|
| MCU | STM32F100C6Tx (Cortex‑M3, 24 MHz) |
| IDE | STM32CubeIDE ≥ 1.13 (bundled GCC arm-none-eabi) |
| HAL | STM32Cube F1 (HAL driver bundled per exN) |
| Simulator | Proteus 8 Professional |
| Tested OS | Windows 10/11 |

## Build & flash

1. Open STM32CubeIDE → **File ▸ Import ▸ Existing Projects into Workspace**.
2. Point it at `exN/stm32/`. Each `exN` is a standalone project.
3. **Project ▸ Build All** (`Ctrl+B`). Output `.elf` / `.hex` lands in `exN/stm32/Debug/` (gitignored).
4. Simulate: open `exN/proteus/Lab2_exN.pdsprj` in Proteus, load the `.hex` into the MCU model, then **Play**.
5. Flash to real hardware: ST‑LINK ▸ **Run** from STM32CubeIDE.

## Reports & references

- 📄 [`docs/requirement.pdf`](docs/requirement.pdf) — official lab brief (Lab 2 Timer)
- 🎬 [`docs/videos/ex9_demo.mp4`](docs/videos/ex9_demo.mp4) — Proteus demo of ex9 (digital clock)

## License

STMicroelectronics sample code is governed by the license shipped in each file header (`Copyright (c) 2024 STMicroelectronics`). Code written by the team is for academic use only — no commercial license.
