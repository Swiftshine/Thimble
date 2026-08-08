# Thimble
Modding framework for **Yoshi's Woolly World** code mods.

For any questions regarding modding the game, feel free to ask in the [Good-Feel Modding Discord](https://discord.gg/fk8X8EgRkx).

## Notable Features
- Bypass BPE-only archiving restrictions
- Custom actors
- Misc. configurable settings via bson
  - You can compile `content/thimble/config.json` into `config.bson` via [fleece](https://github.com/Swiftshine/fleece).

## Setup Guide
### Compiling
Install [Tachyon](https://github.com/Zenith-Team/Tachyon) (requires [Node.js](https://nodejs.org/) v24+)
```yml
npm i -g --allow-remote=root https://github.com/Zenith-Team/Tachyon/releases/latest/download/tachyon.tgz
```
Build and run the project for your region (example with `US`)
```rb
tachyon pm install
tachyon compile US
tachyon launch US
```
