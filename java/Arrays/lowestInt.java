public class lowestInt {
    public static void main(String[] args) {
        int[] arr={9,5,4,2,7,3,12,77};
        int minVal = arr[1];

        for(int i : arr){
            if(i<minVal){
                minVal = i;
            }
        }

        System.out.println(minVal);
    }
}
