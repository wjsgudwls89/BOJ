package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ2628 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); //선언
		//String s = bf.readLine(); //String
		//int i = Integer.parseInt(bf.readLine());
		//Scanner sc = new Scanner(System.in);
		StringTokenizer st = new StringTokenizer(bf.readLine()," ");

		int m =  Integer.parseInt(st.nextToken());
		int n =  Integer.parseInt(st.nextToken());
		int map[][] = new int[n+1][m+1];
		st = new StringTokenizer(bf.readLine()," ");
		int num = Integer.parseInt(st.nextToken());
		int ny = 0,nx = 0;

		List<Integer> ansy = new ArrayList<>();
		List<Integer> ansx = new ArrayList<>();
		ansy.add(0);
		ansx.add(0);
		for (int i = 0; i < num; i++) {
			st = new StringTokenizer(bf.readLine()," ");
			int lr = Integer.parseInt(st.nextToken());
			int cut =  Integer.parseInt(st.nextToken());
			if(lr == 0) {
				ansy.add(cut);
			}
			else {
				ansx.add(cut);
			}
		}

		int cnt = 0;
		ansy.sort(null);
		ansx.sort(null);
		ansy.add(n);ansx.add(m);
		int tempy = ansx.get(0);
		int tempyIdx = ansy.get(0);
		int tempx = ansx.get(0);
		int tempxIdx = ansx.get(0);
		if(ansy.size() > 1){
			tempy = 0;

			for (int i = 0; i < ansy.size()-1; i++) {
				if(ansy.get(i+1) - ansy.get(i) > tempy) {
					tempy = ansy.get(i+1) - ansy.get(i);
					tempyIdx = ansy.get(i);
				}
			}
		}
		if(ansx.size()>1) {
			tempx = 0;
			for (int i = 0; i < ansx.size()-1; i++) {
				if(ansx.get(i+1) - ansx.get(i) > tempx) {
					tempx = ansx.get(i+1) - ansx.get(i);
					tempxIdx = ansx.get(i);
				}
			}
		}
		System.out.println(tempy*tempx);
	}
}
