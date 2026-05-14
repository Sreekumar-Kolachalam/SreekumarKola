print("input binary string:");
binary_input=input();
length=len(binary_input);
dec=0;
if(length>8):
    print("invalid input");
    exit();    
for i in range(length) :
    if(binary_input[i] not in ['0','1']):
        print("invalid input");
        exit();
    dec=dec+int(binary_input[i])*(2**(length-i-1));
print("decimal value:",dec);

