package com.chocho.prim;

import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class Graph {
    static final int MaxNum = 10005;  //无穷大数
    int size = 100;                 //矩阵大小
    private List<Edge> edgeList;             //边集
    private int AdjMatrix[][];  //邻接矩阵

    public Graph() {
    }

    public Graph(List<Edge>  edgeList){
        this.edgeList = edgeList;
    }

    public void ToAdjacencyMatrix(){
        AdjMatrix = new int[][]{
                {0, 18, MaxNum, MaxNum, MaxNum, 16, MaxNum},
                {18, 0, 22, MaxNum, MaxNum, MaxNum, MaxNum},
                {MaxNum, 22, 0, 20, MaxNum, 24, 16},
                {MaxNum, MaxNum, 20, 0, 26, MaxNum, 7},
                {MaxNum, MaxNum, MaxNum, 26, 0, 17, MaxNum},
                {16, MaxNum, 24, MaxNum, 17, 0, 19},
                {MaxNum, MaxNum, 16, 7, MaxNum, 19, 0}
        };
        //初始化邻接矩阵
//        for(int i = 0; i < AdjMatrix.length; i++)
//            for(int j = 0; j < AdjMatrix[i].length; j++)
//                AdjMatrix[i][j] = 0;
//        Iterator<Edge> it = edgeList.iterator();
//        while (it.hasNext()){
//            Edge e = (Edge) it.next();
//            if("v1".equals(e.getFrom().getName()) == true){
//
//            }
//        }
    }

    public int NameToIndex(String vexName){

        int index = -1;

        if("v1".equals(vexName) == true){
            index = 0;
        }else if("v2".equals(vexName) == true){
            index = 1;
        }else if("v3".equals(vexName) == true){
            index = 2;
        }else if("v4".equals(vexName) == true){
            index = 3;
        }else if("v5".equals(vexName) == true){
            index = 4;
        }else if("v6".equals(vexName) == true){
            index = 5;
        }else if("v7".equals(vexName) == true){
            index = 6;
        }else if("v8".equals(vexName) == true){
            index = 7;
        }else if("v9".equals(vexName) == true){
            index = 8;
        }else if("v10".equals(vexName) == true){
            index = 9;
        }

        return index;
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
