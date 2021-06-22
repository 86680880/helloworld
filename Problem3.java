package test0103;

public class Problem3 {
	/**
	 * 时间复杂度O(len1*len2). 空间复杂度O(len1*len2).
	 * @param str1 the first string which will be operated.
	 * @param str2 the target string
	 * @return the operations  
	 */
	public static int operationMin(String str1,String str2) {
		
		int len1 = str1.length();
		int len2 = str2.length();
		if(len1==0||len2==0) {
			return Math.max(len1, len2);//如果str中的任何一个为空，则删除/插入另一个字符串。
		}
		int[][] dp = new int[len1+1][len2+1];
		for(int i=0;i<len1+1;i++) {
			dp[i][0]=i;
		}
		for(int j=0;j<len2+1;j++) {
			dp[0][j]=j;
			
		}
		char[] arr1 = str1.toCharArray();
		char[] arr2 = str2.toCharArray();
		for(int i=1;i<=len1;i++) {
			for(int j=1;j<=len2;j++) {
				if(arr1[i-1]==arr2[j-1]) {
					dp[i][j]=dp[i-1][j-1];//如果arr1[i-1]和arr2[j-1]相同，则无需操作
				}
				else {
                    int ope1 = Math.min(dp[i][j-1],dp[i-1][j]);//添加/删除
                    int ope2 = dp[i-1][j-1];//替换
					dp[i][j] = Math.min(ope1,ope2)+1;
				}
			}
		}
		return dp[len1][len2];
	}
	public static void main(String[] args) {
		System.out.println(operationMin("aaa","bbb"));
		System.out.println(operationMin("","bbb"));
		System.out.println(operationMin("b","bbb"));
	}

}
