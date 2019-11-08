

function clickOnItemOfList( ){
    console.log("js::ListView screenName=" + screenName)
    var obj = { sceneName: screenName, listViewId:  listId, ListItem:  index , event: "onList"  };
    return  JSON.stringify(obj);
}

function clickOnButton( butonName){
    console.log("js::ListView screenName=" + screenName)
    var obj = { sceneName: screenName, listViewId:  0, buttonName:  butonName, event: "onButton" };
    return  JSON.stringify(obj);
}


function clickOnBack( ){
    console.log("js::ListView screenName=" + screenName)
    var obj = { sceneName: screenName, event: "onBack" };
    return  JSON.stringify(obj);
}
