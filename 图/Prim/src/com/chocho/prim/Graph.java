package com.chocho.prim;

import java.util.Arrays;
import java.util.List;

public class  Graph {
    public static final int MaxNum = 10005;  //无穷大数
    public int size = 7;                 //矩阵大小
    public List<Edge> edgeList;             //边集
    public int AdjMatrix[][];  //邻接矩阵

    public Graph() {
    }

    public Graph(int M[][]){
        AdjMatrix = M;
    }
    public Graph(List<Edge>  edgeList){
        this.edgeList = edgeList;
        AdjMatrix = new int[size][size];
    }

    public Closedge[] getPrim(){
        /**1.创建辅助数组并初始化**/
        Closedge closedge = new Closedge();
        Closedge c = new Closedge();
        c .v = 0;
        c.known = false;
        c.weight = 0;
        c.adjv = 0;
        closedge.getClosedge()[0] = c;
        for(int i = 1; i < closedge.getClosedge().length; i++){
            Closedge t = new Closedge();
            t.v = i;
            t.known = false;
            t.weight = MaxNum;
            t.adjv = 0;
            closedge.getClosedge()[i] = t;
        }
        /**2.Prim算法**/
        int END = -MaxNum;
        int i = 0, j = 0;
        int num = 0;
        while(j != END) {
            i = 0;
            num++;
            closedge.getClosedge()[j].x = num;
            closedge.getClosedge()[j].known = true;
            while (i < closedge.getClosedge().length) {
                /**扫描每一行**/
                if (closedge.getClosedge()[i].known == false) {
                    /**修改dv,pv**/
                    if (this.AdjMatrix[j][i] < closedge.getClosedge()[i].weight) {
                        closedge.getClosedge()[i].weight = this.AdjMatrix[j][i];
                        closedge.getClosedge()[i].adjv = j;
                    }
                }
                ++i;
            }
            /**找到下一个顶点**/
            int k = 0;
            int flag = 1;
            while(k < closedge.getClosedge().length){
                if(closedge.getClosedge()[k].known == false && flag == 1){
                    j = k;
                    flag = 0;
                }
                else if(closedge.getClosedge()[k].known == false && closedge.getClosedge()[k].weight < closedge.getClosedge()[j].weight){
                    j = k;
                }
                k++;
            }
            if(closedge.getClosedge()[j].known == true){
                j = END;
            }
        }

        return closedge.getClosedge();
    }

    @Override
    public String toString() {
        return "Graph{" +
                "size=" + size +
                ", edgeList=" + edgeList +
                ", AdjMatrix=" + Arrays.toString(AdjMatrix) +
                '}';
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public List<Edge> getEdgeList() {
        return edgeList;
    }

    public void setEdgeList(List<Edge> edgeList) {
        this.edgeList = edgeList;
    }

    public int[][] getAdjMatrix() {
        return AdjMatrix;
    }

    public void setAdjMatrix(int[][] adjMatrix) {
        AdjMatrix = adjMatrix;
    }
}
