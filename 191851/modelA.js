class Slingshot{
    constructor(bodyA, pointB, stiff, leng){
        var options = {
            bodyA: bodyA,
            pointB: pointB,
            stiffness: stiff,
            length: leng
        }
        this.sling = Constraint.create(options);
        this.pointB=pointB;

        World.add(world, this.sling);

    }
    fly(){
        this.sling.bodyA =null;
    }
    display(){
        if(this.sling.bodyA){
        var pointA = this.sling.bodyA.position;
        var pointB = this.pointB;
        
        strokeWeight(4);
        stroke("red");
        line(pointA.x + 10, pointA.y - 20, pointB.x, pointB.y);
        }
        }
    
}