class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
         List<List<String>>res=new ArrayList<>();
        TreeMap<String,Integer>mp=new TreeMap<>();
        Arrays.sort(products);
        List<String>list=Arrays.asList(products);
        for(int i=0;i<products.length;i++){
            mp.put(products[i],i);
        }
        String key="";
        for(char c:searchWord.toCharArray()){
            key+=c;
            String from=mp.ceilingKey(key);
            String to=mp.floorKey(key+"~");
            if(to==null|| from==null){
                break;
            }
            res.add(list.subList(mp.get(from),Math.min(mp.get(from)+3,mp.get(to)+1)));
        }
        while(res.size()<searchWord.length()){
            res.add(new ArrayList<>());
        }
        return res;
    }
}