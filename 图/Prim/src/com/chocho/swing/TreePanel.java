package com.chocho.swing;

import com.chocho.prim.Closedge;
        import java.awt.*;

public class TreePanel extends Panel {
    /**添加定位线条**/
    public int line[][];
    public Closedge c[];
    public String lName;
    public boolean first;

    public TreePanel(){
        Leaf l = new Leaf();
        line = l.leaves;
        for(int i = 0; i < line.length; i++) {
            line[i][0] -= 224;
        }
        first = true;
    }
    public void setTree(Closedge c[]){
        this.c= c;
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Color color = new Color(238,238,238);
        Graphics2D g2 = (Graphics2D)g;
        Font font = new Font("楷体", Font.PLAIN, 30);
        g2.setStroke(new BasicStroke(3.0f));
        g.setFont(font);
        if(first == true){
            //显示线条与数字
            g.setColor(Color.BLACK);
            g2.setColor(Color.BLACK);
            drawLineAndNumber(g, g2);
            first = false;
        }
        else {
            //隐藏线条与数字
            g.setColor(color);
            g2.setColor(color);
            drawLineAndNumber(g, g2);

            Thread thr = new Thread();
            for(int num = 1; num <= c.length; num++){
                for(int i = 0;i < c.length; i++){
                    //找到某一条边
                    if(c[i].x == num) {
                        lName = c[i].v + "-" + c[i].adjv;
                        if (lName != null && lName != "") {
                            //显示线条与数字
                            g.setColor(Color.BLACK);
                            g2.setColor(Color.BLACK);
                            drawLineAndNumber(g, g2, lName);
                            c[i].known = false;
                            try {
                                thr.sleep(500);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                        }
                    }
                }
             }
        }
    }

    public void drawLineAndNumber(Graphics g, Graphics2D g2, String name){
        //线V1-V2/V2-V1
        if(name.equals("0-1") || name.equals("1-0")) {
            g2.drawLine(line[0][0], line[0][1] + 64, line[1][0] + 64, line[1][1]);
            g.drawString("1", (line[0][0] + line[1][0] + 64) / 2 - 5, (line[0][1] + 64 + line[1][1]) / 2 - 5);
        }else if(name.equals("0-6") || name.equals("6-0")) {
            //线V1-V7
            g2.drawLine(line[0][0] + 32, line[0][1] + 64, line[6][0] + 32, line[6][1]);
            g.drawString("6", (line[0][0] + 32 + line[6][0] + 32) / 2 - 15, (line[0][1] + 64 + line[6][1]) / 2 - 5);
        }else if(name.equals("0-2") || name.equals("2-0")){
            //线V1-V3
            g2.drawLine(line[0][0] + 64, line[0][1] + 64, line[2][0], line[2][1]);
            g.drawString("2", (line[0][0] + 64 + line[2][0])/2 - 5, (line[0][1] + 64 + line[2][1])/2 - 5);
        }else if(name.equals("3-1") || name.equals("1-3")) {
            //线V2-V4
            g2.drawLine(line[1][0] + 32, line[1][1] + 64, line[3][0] + 32, line[3][1]);
            g.drawString("7", (line[1][0] + 32 + line[3][0] + 32) / 2 - 15, (line[1][1] + 64 + line[3][1]) / 2 - 5);
        }else if(name.equals("6-1") || name.equals("1-6")) {
            //线V2-V7
            g2.drawLine(line[1][0] + 64, line[1][1] + 64, line[6][0], line[6][1]);
            g.drawString("8", (line[1][0] + 64 + line[6][0]) / 2 - 5, (line[1][1] + 64 + line[6][1]) / 2 - 5);
        }else if(name.equals("2-6") || name.equals("6-2")) {
            //线V3-V7
            g2.drawLine(line[2][0], line[2][1] + 64, line[6][0] + 64, line[6][1]);
            g.drawString("9", (line[2][0] + line[6][0] + 64) / 2 - 5, (line[2][1] + 64 + line[6][1]) / 2 - 5);
        }else if(name.equals("2-4") || name.equals("4-2")) {
            //线V3-V5
            g2.drawLine(line[2][0] + 32, line[2][1] + 64, line[4][0] + 32, line[4][1]);
            g.drawString("10", (line[2][0] + 32 + line[4][0] + 32) / 2 + 5, (line[2][1] + 64 + line[4][1]) / 2 - 5);
        }else if(name.equals("3-6") || name.equals("6-3")) {
            //线V4-V7
            g2.drawLine(line[3][0] + 64, line[3][1], line[6][0], line[6][1] + 64);
            g.drawString("11", (line[3][0] + 64 + line[6][0]) / 2 - 5, (line[3][1] + line[6][1] + 64) / 2 - 5);
        }else if(name.equals("3-5") || name.equals("5-3")) {
            //线V4-V6
            g2.drawLine(line[3][0] + 64, line[3][1] + 64, line[5][0], line[5][1]);
            g.drawString("12", (line[3][0] + 64 + line[5][0]) / 2 - 5, (line[3][1] + 64 + line[5][1]) / 2 - 5);
        }else if(name.equals("4-6") || name.equals("6-4")) {
            //线V5-V7
            g2.drawLine(line[4][0], line[4][1], line[6][0] + 64, line[6][1] + 64);
            g.drawString("3", (line[4][0] + line[6][0] + 64) / 2 - 5, (line[4][1] + line[6][1] + 64) / 2 - 5);
        }else if(name.equals("4-5") || name.equals("5-4")) {
            //线V5-V6
            g2.drawLine(line[4][0], line[4][1] + 64, line[5][0] + 64, line[5][1]);
            g.drawString("4", (line[4][0] + line[5][0] + 64) / 2 - 5, (line[4][1] + 64 + line[5][1]) / 2 - 5);
        }else if(name.equals("5-6") || name.equals("6-5")) {
            //线V6-V7
            g2.drawLine(line[5][0] + 32, line[5][1], line[6][0] + 32, line[6][1] + 64);
            g.drawString("5", (line[5][0] + 32 + line[6][0] + 32) / 2 + 5, (line[5][1] + line[6][1] + 64) / 2 - 5);
        }
    }

    public void drawLineAndNumber(Graphics g, Graphics2D g2){
        //线V1-V2
        g2.drawLine(line[0][0], line[0][1] + 64, line[1][0] + 64, line[1][1]);
        g.drawString("1", (line[0][0] + line[1][0] + 64)/2 - 5, (line[0][1] + 64 + line[1][1])/2 - 5);
        //线V1-V7
        g2.drawLine(line[0][0] + 32, line[0][1] + 64, line[6][0] + 32, line[6][1]);
        g.drawString("6", (line[0][0] + 32 + line[6][0] + 32)/2 - 15, (line[0][1] + 64 + line[6][1])/2 - 5);
        //线V1-V3
        g2.drawLine(line[0][0] + 64, line[0][1] + 64, line[2][0], line[2][1]);
        g.drawString("2", (line[0][0] + 64 + line[2][0])/2 - 5, (line[0][1] + 64 + line[2][1])/2 - 5);
        //线V2-V4
        g2.drawLine(line[1][0] + 32, line[1][1] + 64, line[3][0] + 32, line[3][1]);
        g.drawString("7", (line[1][0] + 32 + line[3][0] + 32)/2 - 15, (line[1][1] + 64 + line[3][1])/2 - 5);
        //线V2-V7
        g2.drawLine(line[1][0] + 64, line[1][1] + 64, line[6][0], line[6][1]);
        g.drawString("8", (line[1][0] + 64 + line[6][0])/2 - 5, (line[1][1] + 64 + line[6][1])/2 - 5);
        //线V3-V7
        g2.drawLine(line[2][0], line[2][1] + 64, line[6][0] + 64, line[6][1]);
        g.drawString("9", (line[2][0] + line[6][0] + 64)/2 - 5, (line[2][1] + 64 + line[6][1])/2 - 5);
        //线V3-V5
        g2.drawLine(line[2][0] + 32, line[2][1] + 64, line[4][0] + 32, line[4][1]);
        g.drawString("10", (line[2][0] + 32 + line[4][0] + 32)/2 + 5, (line[2][1] + 64 + line[4][1])/2 - 5);
        //线V4-V7
        g2.drawLine(line[3][0] + 64, line[3][1], line[6][0], line[6][1] + 64);
        g.drawString("11", (line[3][0] + 64 + line[6][0])/2 - 5, (line[3][1] + line[6][1] + 64)/2 - 5);
        //线V4-V6
        g2.drawLine(line[3][0] + 64, line[3][1] + 64, line[5][0], line[5][1]);
        g.drawString("12", (line[3][0] + 64 + line[5][0])/2 - 5, (line[3][1] + 64 + line[5][1])/2 - 5);
        //线V5-V7
        g2.drawLine(line[4][0], line[4][1], line[6][0] + 64, line[6][1] + 64);
        g.drawString("3", (line[4][0] + line[6][0] + 64)/2 - 5, (line[4][1] + line[6][1] + 64)/2 - 5);
        //线V5-V6
        g2.drawLine(line[4][0], line[4][1] + 64, line[5][0] + 64, line[5][1]);
        g.drawString("4", (line[4][0] + line[5][0] + 64)/2 - 5, (line[4][1] + 64 + line[5][1])/2 - 5);
        //线V6-V7
        g2.drawLine(line[5][0] + 32, line[5][1], line[6][0] + 32, line[6][1] + 64);
        g.drawString("5", (line[5][0] + 32 + line[6][0] + 32)/2 + 5, (line[5][1] + line[6][1] + 64)/2 - 5);
    }
}
