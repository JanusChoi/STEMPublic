# STEMPublic
This Repo only for who have attended the STEM Public class

亲爱的同学们好，

以下为本仓库整体目录(点击链接快速访问)：

-   [STEMPublic](#stempublic)
    -   [5分钟学会MarkDown语法](#分钟学会markdown语法)
    -   [如何在家远程连接树莓派](#如何在家远程连接树莓派)
    -   [把树莓派当作一台电脑主机](#把树莓派当作一台电脑主机)
    -   [童创未来作品想法发布](#童创未来作品想法发布)
    -   [童创未来竞赛时间节点](#童创未来竞赛时间节点)

## 5分钟学会MarkDown语法
参考：https://sspai.com/post/25137

学会MarkDown的好处：
- 从此不再烦恼排版问题，可以专注于文字本身
- 快速兼容GitHub，Jupyter Notebook，Kaggle，R语言社区等等（因为这就是程序员用的写作工具）
- 轻松转换成html，pdf，word
- 高级应用还可以兼容更多，如LaTeX

## 如何在家远程连接树莓派

1. 先把SD卡插入到USB读卡器中，连接到电脑上
2. 这时你会看到一个叫boot的盘出现
3. 在桌面新增文件，复制粘贴以下内容填入
注意：
- 把 ssid= 后面的 JaCYYs  改成你家的wifi名字，保留双引号
- 把 psk= 后面的 12345678 改成你家的wifi密码，保留双引号

```
country=CN
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
network={
ssid="JaCYYs"
psk="12345678"
}
```

4. 保存文件，命名为 wpa_supplicant.conf （**注意一定要用这个文件名**）
5. 安全退出U盘后，把小sd卡装入树莓派中，打开树莓派电源
**注意：大家回家尽量用手机充电器的充电头来给树莓派供电，不然有可能电压不足**

6. 在这个[页面](http://www.hide-windows.com/Download/ipscan.exe)下载工具 ipscan
7. 打开工具扫描查看树莓派的IP地址，步骤如下图
![](https://ws4.sinaimg.cn/large/006tNc79gy1g36ydk0j3lj30s20kjwlr.jpg)
树莓派hostname都已改成各位同学名字的拼音，如 yuxiutong 即余修桐
8. 用一下用户名密码，远程连接上树莓派 done ~~~！！
用户名：pi
密码：raspberry
（如果找不到远程桌面工具，可按windows键+R，然后键入mstsc，然后回车打开
9. 点击左上角按钮，探索一下树莓派里面都有什么吧！
![](https://ws1.sinaimg.cn/large/006tNc79gy1g36ylnglxgj30jx0j63zo.jpg)

## 把树莓派当作一台电脑主机

如果实在无法远程上树莓派，你可以在树莓派上找到各种连接端口，然后：
![](https://s3-eu-west-1.amazonaws.com/raspberrypi-education/teaching-physical-computing/plug-in.gif)
1. 连接HDMI线到显示器
2. 连接网线
3. 连接USB键盘和鼠标
4. enjoy

## 童创未来作品想法发布

请大家在issue中发布你们的作品，issue已有一个示例。**5月22日前提交**
若近期有同学实在因考试事宜过于繁忙，请直接联系蔡老师。

步骤：
1. [注册github](https://github.com/join?source=header-home)（**注意注册时暂停浏览器的即时翻译插件**）
2. 打开[课程仓库](https://github.com/JanusChoi/STEMPublic)
3. 点击最上方的issue之后点击New Issue，如下图
![](https://ws4.sinaimg.cn/large/006tNc79gy1g36xd3vvhvj31lg0putm4.jpg)
4. 复制以下模板填写后发布：
```
## 小组名称：
## 学生姓名：
## 作品名称：
## 作品描述：
## 功能点描述
1.
2.
3.
## 创新性描述
1.
2.
3.
## 作品意义
1.
2.
3.
## 实现方式
### 模块一
1.
2.
3.
### 模块二
1.
2.
3.
```

## 童创未来竞赛时间节点

请同学们注意以下时间节点，节点任务的完成有助于大家顺利提交作品。

![](https://ws1.sinaimg.cn/large/006tNc79gy1g36xev861hj30ov0ghgof.jpg)
