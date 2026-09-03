# 井字棋

1. 此程序为井字棋
2. 按照程序提示，分别由`X`和`O`输入代表位置的数字后回车
3. 当棋子连成一条线时，决出赢家
4. 普通模式中玩家有无数个棋子，下满棋盘后平局
5. 仅有3个棋子模式中玩家仅有3个棋子，下第4个棋子时，系统将收回第一个棋子
6. 游戏结束后，程序将输入当前的棋盘到表格文件`Tic-Tac-Toe.csv`

## 如何下载？

前往 [GitHub Release](https://github.com/BlazeSnow/Tic-Tac-Toe/releases/latest) 下载对应系统的可执行文件。

文件命名格式为 `Tic-Tac-Toe-<版本>-<系统>-<架构>`，各平台对应关系如下：

| 文件名后缀           | 适用平台               |
| -------------------- | ---------------------- |
| `-windows-x64.exe`   | Windows x64            |
| `-windows-arm64.exe` | Windows ARM64          |
| `-linux-x64`         | Linux x64              |
| `-linux-arm64`       | Linux ARM64            |
| `-macos-x64`         | macOS（Intel）         |
| `-macos-arm64`       | macOS（Apple Silicon） |

## Linux / macOS 额外处理

```sh
sudo chmod +x <可执行文件>
```

## 更新日志

见 [CHANGELOG.md](./CHANGELOG.md)

## 许可证

[MIT](./LICENSE)
