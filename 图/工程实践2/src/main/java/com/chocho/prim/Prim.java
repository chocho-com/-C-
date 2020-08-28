package com.chocho.prim;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Prim {
    static final int MaxNum = 10000;
    public void getPrim(){
    Graph graph = new Graph();
    graph.ToAdjacencyMatrix();
        //创建辅助数组并初始化
        Closedge closedge = new Closedge();
        Closedge c = new Closedge();
        c .v = 0;
        c.known = false;
        c.dv = 0;
        c.pv = 0;
        closedge.getClosedge()[0] = c;
        for(int i = 1; i < closedge.getClosedge().length; i++){
            Closedge t = new Closedge();
            t.v = i;
            t.known = false;
            t.dv = MaxNum;
            t.pv = 0;
            closedge.getClosedge()[i] = t;
        }
        //Prim算法
        int END = -MaxNum;
        int i = 0, j = 0;
       while(j != END) {
           i= 0;
           closedge.getClosedge()[j].known = true;
           while (i < closedge.getClosedge().length) {//扫描每一行
               if (closedge.getClosedge()[i].known == false) {//更新数据
                   //修改dv,pv
                   if (graph.A[j][i] < closedge.getClosedge()[i].dv) {
                       closedge.getClosedge()[i].dv = graph.GraphMatrix[j][i];
                       closedge.getClosedge()[i].pv = j;
                   }
               }
               ++i;
           }
           //找到下一个顶点
           int k = 0;
           int flag = 1;
           while(k < closedge.getClosedge().length){
               if(closedge.getClosedge()[k].known == false && flag == 1){
                   j = k;
                   flag = 0;
               }
               else if(closedge.getClosedge()[k].known == false && closedge.getClosedge()[k].dv < closedge.getClosedge()[j].dv){
                   j = k;
               }
               k++;
           }
           if(closedge.getClosedge()[j].known == true){
               j = END;
           }
       }

       for(int h = 0; h < closedge.getClosedge().length; h++){
           System.out.println(closedge.getClosedge()[h].toString());
       }
    }
}
