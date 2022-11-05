class Solution:
    def decodeString(self, s: str) -> str:
        myList = [];
        for i in s:
            if(i!=']'):
                myList.append(i);
            else:
                pattern = '';
                while(myList[-1]!='['):
                    pattern = myList[-1] + pattern;
                    myList.pop();
                
                myList.pop();
                number = '';
                while(len(myList)!=0 and myList[-1]<='9' and myList[-1]>='0' ):
                    number = myList[-1] + number;
                    myList.pop();
                
                myList.append(pattern * int(number));
            
        return ''.join(myList);
        