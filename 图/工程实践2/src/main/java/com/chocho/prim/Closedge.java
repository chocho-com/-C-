package com.chocho.prim;

public class Closedge {
    static final int MaxNum = 10000;
    public int v;
    public boolean known;
    public int dv;
    public int pv;
    Closedge closedge[] = new Closedge[7];

    public Closedge(){
    }
    @Override
    public String toString() {
        return "v=" + v + "  known=" + known + "  dv=" + dv + "  pv=" + pv;
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

    public int getDv() {
        return dv;
    }

    public void setDv(int dv) {
        this.dv = dv;
    }

    public int getPv() {
        return pv;
    }

    public void setPv(int pv) {
        this.pv = pv;
    }

    public Closedge[] getClosedge() {

        return closedge;
    }

    public void setClosedge(Closedge[] closedge) {
        this.closedge = closedge;
    }

}
