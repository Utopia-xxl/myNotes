var fib = function(n) {
    if(n<=1) return n;
    let num1=0,num2=1;
    for(let i=2;i<=n;i++){
        let temp = num2;
        num2 = num1+num2;
        num1 = temp;
    }
    return num2;
};

// 优化了dp数组