package com.chocho.prim;

public class Closedge {
    public static final int MaxNum = 10000;
    public int v;
    public boolean known;
    public int weight;
    public int adjv;
    Closedge closedge[] = new Closedge[7];
    public int x;

    public Closedge(){

    }

    @Override
    public String toString() {
        return "Closedge{" +
                "v=" + v +
                ", known=" + known +
                ", weight=" + weight +
                ", adjv=" + adjv;
    }

    public static int getMaxNum() {
        return MaxNum;
    }

    public int getV() {
        return v;
    }

    public void setV(int v) {
        this.v = v;
    }

    public boolean isKnown() {
        return known;
    }

    public void setKnown(boolean known) {
        this.known = known;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getAdjv() {
        return adjv;
    }

    public void setAdjv(int adjv) {
        this.adjv = adjv;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public Closedge[] getClosedge() {
        return closedge;
    }

    public void setClosedge(Closedge[] closedge) {
        this.closedge = closedge;
    }
}
