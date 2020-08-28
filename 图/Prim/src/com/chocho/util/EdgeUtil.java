package com.chocho.util;

public class EdgeUtil {
    public static int NameToIndex(String vexName){
        int index = -1;

        if("V1".equals(vexName) == true){
            index = 0;
        }else if("V2".equals(vexName) == true){
            index = 1;
        }else if("V3".equals(vexName) == true){
            index = 2;
        }else if("V4".equals(vexName) == true){
            index = 3;
        }else if("V5".equals(vexName) == true){
            index = 4;
        }else if("V6".equals(vexName) == true){
            index = 5;
        }else if("V7".equals(vexName) == true){
            index = 6;
        }

        return index;
    }

    public static String IndexToName(int index){
        String vexName = "";

        if(index == 0){
            vexName = "V1";
        }else if(index == 1){
            vexName = "V2";
        }else if(index == 2){
            vexName = "V3";
        }else if(index == 3){
            vexName = "V4";
        }else if(index == 4){
            vexName = "V5";
        }else if(index == 5){
            vexName = "V6";
        }else if(index == 6){
            vexName = "V7";
        }

        return vexName;
    }
}
