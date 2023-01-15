# Game Server Manager

用于管理UE4服务器的Linux程序

# 功能预设

1. 此进程以命令行启动，命令行为需要启动的游戏进程
2. 通过Socket发送消息，以Json格式发送，可能包括CommandType + Parameters的形式
    比如发送GetAllServers，服务器返回Json，包括所有的服务器和IP+Port
3. 拥有简单用户管理功能，一个进程对应一个游戏  
4. 高级进程管理，再开发插件，插件有个子系统，专门与服务器通讯，实现用户状态更新，进程Tick（发送Socket消息）等

# 重点
1. 进程管理
2. Socket通信
3. Json解析
4. 子系统与功能设计
5. 游戏插件设计（包含子系统等类，提供服务器获取，好友等功能） 