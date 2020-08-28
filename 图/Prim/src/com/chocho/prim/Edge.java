package com.chocho.prim;

public class Edge {
    public Vex from;            //起点
    public Vex to;              //终点
    public int weight;          //边权值

    public Edge(){}

    public Edge(Vex from, int weight, Vex to){
        this.from = from;
        this.weight = weight;
        this.to = to;
    }

    @Override
    public String toString() {
        return "Edge{" +
                "from=" + from +
                ", to=" + to +
                ", weight=" + weight +
                '}';
    }

    public Vex getFrom() {
        return from;
    }

    public void setFrom(Vex from) {
        this.from = from;
    }

    public Vex getTo() {
        return to;
    }

    public void setTo(Vex to) {
        this.to = to;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }
}
