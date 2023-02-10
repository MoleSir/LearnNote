/* 工厂 */
using System;
using System.Collections.Generic;

namespace FlyweightPatternApplication
{
    public class FlyweightFactory
    {
        public FlyweightFactory()
        {
            this.flyweightDict = new Dictionary<string, Flyweight>();
        }

        // 获取对象
        public Flyweight GetFlyweight(string intrinsicState)
        {
            // 检测是否已经存在
            if (this.flyweightDict.ContainsKey(intrinsicState) == true)
                return this.flyweightDict[intrinsicState];

            // 没有就创建
            Flyweight flyweight = new ConcreteFlyweight(intrinsicState);
            // 添加到字典
            this.flyweightDict.Add(intrinsicState, flyweight);
            return flyweight;
        }

        // 字典
        private Dictionary<string, Flyweight> flyweightDict;
    }
}