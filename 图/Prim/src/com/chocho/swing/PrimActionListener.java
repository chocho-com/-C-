package com.chocho.swing;

import com.chocho.prim.Graph;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PrimActionListener implements ActionListener {
    public Graph G;
    public PrimFrame frame;

    public PrimActionListener(){}

    public PrimActionListener(Graph G, PrimFrame frame){
        this.G = G;
        this.frame = frame;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();
            if(command != "" && command != null){
                if("绘制树图".equals(command)){
                    frame.drawLeafAndBranch();
                }else if("普利姆算法".equals(command)){
                    frame.panel.setTree(G.getPrim());
                }else if("运行程序".equals(command)){
                    frame.closeDrawPanel();
                }
            }else{
                System.out.println("错误");
            }
    }
}
