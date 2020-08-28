package com.chocho.swing;

public class Leaf {
    public int x;
    public int y;
    public int leaves[][] = new int[][]{
            {680, 60},
            {500, 188},
            {860, 188},
            {500, 360},
            {860, 360},
            {680, 488},
            {680, 274}
    };

    public Leaf(){}

    public Leaf(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int[][] getLeaves() {
        return leaves;
    }

    public void setLeaves(int[][] leaves) {
        this.leaves = leaves;
    }
}
