import java.util.*;

public class BOJ2870 {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

       String ka = sc.nextLine();
        String str ="";
        int k = Integer.parseInt(ka);

        List<String> ans = new ArrayList<>();
        boolean flag = false;
        for (int i = 0; i < k; i++) {
            String a = sc.nextLine();
            flag = false;
            for (int j = 0; j < a.length(); j++) {
                if (a.charAt(j) - '0' < 10) {
                    flag =false;
                    str += a.charAt(j);
                } else {
                    if (!str.equals("")) {
                        ans.add(str);
                        str = "";
                        flag = true;
                    }
                }
            }
            if (!flag) {
                ans.add(str);
                str = "";
                flag =true;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if(ans.get(i).equals("")) {ans.remove(i); i--; continue;}
            if(ans.get(i).charAt(0) == '0' && ans.get(i).length()>1){
                String temp = ans.get(i);
                int idx= 1;
                while(true){

                        temp = temp.substring(idx);

                     if(temp.length() == 1 || temp.charAt(0) != '0')
                         break;
                }
                ans.remove(i);
                ans.add(i,temp);
            }
        }
        //System.out.println(ans);

        ans.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(o1.length()<o2.length()){
                    return -1;
                }
                else if(o1.length() == o2.length()){
                    return o1.compareTo(o2);
                }
                else return 1;
            }
        });
        for (int i = 0; i < ans.size(); i++) {
            System.out.printf("%s\n",ans.get(i));
        }

        }
}
