// I want you to make two changes to the javascript code that i'll paste below, then respond only with the modified code. Firstly, modify the "constructor" function to add two parameters, named "stiff" and "leng". The two parameters will be used in the function to customize the two values of stiffness and length respectively, which are currently constant (0.04 and 100). Secondly: I want you to modify the "display" function to change its color from turquoise to red, and to shift the line drawn by 10px on the x axis and -20px on the y axis. Don't make other changes to the code besides what I described above.

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
        line(pointA.x + 10, pointA.y - 20, pointB.x + 10, pointB.y - 20);
        }
        }
    
}