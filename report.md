# 期中Project -- Simple Nethack

1 - 运行方法和操作方法:
   - 见 README.md
  
2 - 设计思路 : 
   - 封装对象:
     - > 前不久看过一个 ***pimpl*** (pointer to implement) 的设计方法，将文件之间的编译关系降至最低，同时用户只看到接口，看不到类数据成员，增强封装性。**但是**，当我真正写代码的时候才发现装逼是要付出代价的。本来两个文件能搞定的事情现在需要四个文件；修改函数声明时要同时改四个文件；debug的时候只看到指针值看不到类数据的值；因为包含指针必须进行深拷贝，构造函数写到🤮；继承的时候 ***pimpl*** 没卵用，所以最后有继承关系的类没有用这个方法。

   - 代码架构
     -  ```mermaid
        graph LR;
        main--调用---MainMenu;
        MainMenu((MainMenu))--实例化---Game;
        Game---Level;
        Game---Player;
        Level---Map;
        Level---Monstre;
        Level---Prop;
        Map---Room;
        Room---Door;
        Corridor--连接---Room;
        Corridor--连接---Door;
        Player---Prop;
        Player--继承---Creature;
        Monstre--继承---Creature;
        ```

   - 运算符重载
      -  ```Creature &operator-=(const Creature &);```  攻击减血
      -  ```friend Screen &operator<<(Screen &, const T &);``` 向屏幕输出信息
      -  ```bool operator==(const Position &) const;``` 判断位置是否相等
      -  ```bool operator!=(const Position &) const;``` 判断位置是否不等

   - 拓展点
      -  ***BFS*** 随机生成地图
      -  分层
      -  假视野系统

   - 改进空间
      -  更复杂的游戏设计
      -  真视野系统
      -  更清晰的代码架构
      -  更凌乱的地图
      -  更好看的界面
      -  存档
      -  彩蛋？？？
