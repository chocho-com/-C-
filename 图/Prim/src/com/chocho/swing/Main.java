package com.chocho.swing;

import com.chocho.prim.Graph;
import javax.swing.*;

public class Main extends JFrame{
    public static final int MaxNum = 10005;  //无穷大数

    public static void main(String[] args) {
        int M[][] = new int[][]{
            {0, 1, 2, MaxNum, MaxNum, MaxNum, 6},
            {1, 0, MaxNum, 7, MaxNum, MaxNum, 8},
            {2, MaxNum, 0, MaxNum, 10, MaxNum, 9},
            {MaxNum, MaxNum, MaxNum, 0, MaxNum, 12, 11},
            {MaxNum, MaxNum, 10, MaxNum, 0, 4, 3},
            {MaxNum, MaxNum, MaxNum, 12, 4, 0, 5},
            {6, 8, 9, 11, 3, 5, 0} };
        Graph G = new Graph(M);
        PrimFrame pf = new PrimFrame(G);
        pf.setVisible(true);
    }
}
