

function clickOnItemOfList( ){
    console.log("js::ListView screenName=" + screenName)
    var obj = { sceneName:  screenName, listViewId:  listId, ListItem:  index };
    return  JSON.stringify(obj);
}

function clickOnButton( butonName){
    console.log("js::ListView screenName=" + screenName)
    var obj = { sceneName:  screenName, listViewId:  0, buttonName:  butonName };
    return  JSON.stringify(obj);
}


function clickOnBack( ){
    console.log("js::ListView screenName=" + screenName)
    var obj = { sceneName:  screenName };
    return  JSON.stringify(obj);
}
