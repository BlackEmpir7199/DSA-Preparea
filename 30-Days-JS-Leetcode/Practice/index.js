

function orderTea(){
    return function (){
        return `chai is cooking`;
    }
}


console.log(orderTea());