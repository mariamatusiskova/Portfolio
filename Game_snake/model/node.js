class Node {

    constructor(Color) {
        // when something changes all of the observers will be notify
        this.observerCollection = [];

        this.color = Color;
        this.order = 0;
        this.colorsDark = ['#F47E2F', '#F3453F', '#2A9AF6', '#FFFF1C', '#8C3573', '#9E4638', '#110C0B', '#006B56', '#FFCC33', '#E24665', '#FF69B4', '#A020F0', '#B5338A', '#708090', '#C83911', '#335552', '#006C78', '#265E6C', '#A58566', '#3333FF', '#C77A43', '#44D0FE', '#913832', '#DE8D3C'];
        this.colorsBright = ['#F7A46D', '#F77D79', '#6AB8F9', '#FFFFA4', '#AF729D', '#BB7E74', '#585554', '#4D9789', '#FFDB70', '#EB7E94', '#FF96CB', '#BD63F5', '#CB70AC', '#9BA6B1', '#D97458', '#4D7470', '#4D98A1', '#4D8492', '#F0CBA7', '#6666FF', '#D8A17B', '#8FE3FE', '#B27470', '#E8AF77'];
    }

    addObserver(observer) {
        // add observer to array
        this.observerCollection.push(observer);
    }

    changeColor() {

        this.color = food.color;
        this.order = food.order;
    }

    removeObserver(observer) {
        var index = this.observerCollection.indexOf(observer);
        delete this.observerCollection[index];
    }

    // pass message "event" to child notes
    notifyObservers() {
        // for each observer
        for(var observer of this.observerCollection){
            //var node = this.observerCollection[index];

            observer.update(this);

           /* // if node had defined message method, then call the method
            if(typeof(node[event]) == "function")
                node[event](argument);*/
        }
    }
}