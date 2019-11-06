

function clickOnItemOfList( ){
    console.log("js::ListView screenName=" + screenName)
    console.log("js::ListView listId=" + listId)
    console.log("js::ListView index=" + index)

    var obj = { name:  screenName, listId:  listId, city: "New York" };

    return  JSON.stringify(obj);
}


function clickOnButton(screenName, butonName){
    return ""
}
