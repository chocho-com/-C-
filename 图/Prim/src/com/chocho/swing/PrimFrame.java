package com.chocho.swing;

import com.chocho.prim.Graph;
        import javax.swing.*;
        import java.awt.*;

public class PrimFrame extends JFrame{
    //Label设置
    public JLabel _backLable;
    //button设置
    public JButton _initGraph;
    public JButton _prim;
    public JButton _closeBtn;
    //Container
    public Container c;
    //树叶
    public Image leaf;
    public JLabel v[];
    public int leaves[][];
    public String vexs[] = {"V1", "V2", "V3", "V4", "V5", "V6", "V7"};
    //Panel
    public TreePanel panel;

    public PrimFrame(){}

    public PrimFrame(Graph graph){
        c = this.getContentPane();
        this.setTitle("Prim算法实现最小生成树——蒋雁秋");
        init(graph);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        this.setBounds(0, 0, 1200, 678);
        //标题图标
        Image image = new ImageIcon("H:\\素材\\png\\p3.png").getImage();
        this.setIconImage(image);
        this.setLocationRelativeTo(null);
    }

    public void init(Graph graph){
        Font font = new Font("楷体", Font.PLAIN, 24);
        leaves = (new Leaf()).getLeaves();
        /**添加定位叶子**/
        leaf = new ImageIcon("H:\\素材\\png\\p6.png").getImage();
        v = new JLabel[7];
        for(int i = 0; i < vexs.length; i++) {
            v[i] = new JLabel(vexs[i]);
            v[i].setFont(font);
            v[i].setVerticalTextPosition(JLabel.CENTER);
            v[i].setHorizontalTextPosition(JLabel.CENTER);
            v[i].setIcon(new ImageIcon(leaf));
            if("V1".equals(vexs[i])){
                //第一个点
                v[i].setBounds(leaves[i][0], leaves[i][1], 64, 64);
            }else if("V2".equals(vexs[i])){
                //第二个点
                v[i].setBounds(leaves[i][0], leaves[i][1], 64, 64);
            }else if("V3".equals(vexs[i])){
                //第三个点
                v[i].setBounds(leaves[i][0], leaves[i][1], 64, 64);
            }else if("V4".equals(vexs[i])){
                //第四个点
                v[i].setBounds(leaves[i][0], leaves[i][1], 64, 64);
            }else if("V5".equals(vexs[i])){
                //第五个点
                v[i].setBounds(leaves[i][0], leaves[i][1], 64, 64);
            }else if("V6".equals(vexs[i])){
                //第六个点
                v[i].setBounds(leaves[i][0], leaves[i][1], 64, 64);
            }else if("V7".equals(vexs[i])){
                //第七个点
                v[i].setBounds(leaves[i][0], leaves[i][1], 64, 64);
            }
            c.add(v[i]);
            v[i].setVisible(false);
        }
        _initGraph = new JButton("绘制树图");
        _initGraph.setFont(font);
        _initGraph.setBounds(47, 100, 130, 40);
        _prim = new JButton("普利姆算法");
        _prim.setFont(font);
        _prim.setBounds(34, 239, 155, 40);
        _closeBtn = new JButton("运行程序");
        _closeBtn.setFont(font);
        _closeBtn.setBounds(47, 378, 130, 40);
        _backLable = new JLabel();
        //窗口背景
        Image backImg = new ImageIcon("H:\\素材\\jpg\\j2.jpg").getImage();
        _backLable.setIcon(new ImageIcon(backImg));
        _backLable.setBounds(0, 0, 1200, 678);
        panel = new TreePanel();
        panel.setBounds(224, 0, 976, 678);
        panel.setVisible(false);
        //添加至容器,先添加的在上面
        c.add(panel);
        c.add(_initGraph);
        c.add(_prim);
        c.add(_closeBtn);
        c.add(_backLable);
        //监听器
        PrimActionListener pal = new PrimActionListener(graph, this);
        _initGraph.addActionListener(pal);
        _prim.addActionListener(pal);
        _closeBtn.addActionListener(pal);
    }

    public void drawLeafAndBranch(){
        panel.setVisible(true);
        for(int i = 0; i < 7 ; i++){
            v[i].setVisible(true);
        }
    }

    public void closeDrawPanel(){
        panel.setVisible(false);
        for(int i = 0; i < 7 ; i++){
            v[i].setVisible(false);
        }
    }
}
