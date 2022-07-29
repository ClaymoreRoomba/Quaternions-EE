const angle = (45) * (Math.PI / 180);
const vector = [0, 1, 0];

if(vector[0] ** 2 + vector[1] ** 2 + vector[2] ** 2 !== 1){
    console.error("Invalid Vector");
}



class Point{
    constructor(X, Y, Z){
        this.x = X;
        this.y = Y;
        this.z = Z;
    }
    print(){
        console.log([this.x.toFixed(2), this.y.toFixed(2), this.z.toFixed(2)]);
    }
};

class Quaternion{
    constructor(vector = [1, 0, 0], angle = 0){
        this.a = Math.cos(angle/2);
        this.b = vector[0] * Math.sin(angle/2);
        this.c = vector[1] * Math.sin(angle/2);
        this.d = vector[2] * Math.sin(angle/2);
    }
};

class Shape{
    vertices = [];
};

function rotate(q = new Quaternion(), p = new Point()){
    const r = new Point();
    r.x = ((-q.b*p.x - q.c*p.y - q.d*p.z)*(-q.b) + (q.a*p.x + q.c*p.z - q.d*p.y)*(q.a) + (q.a*p.y - q.b*p.z + q.d*p.x)*(-q.d) - (q.a*p.z + q.b*p.y - q.c*p.x)*(-q.c));
    r.y = ((-q.b*p.x - q.c*p.y - q.d*p.z)*(-q.c) - (q.a*p.x + q.c*p.z - q.d*p.y)*(-q.d) + (q.a*p.y - q.b*p.z + q.d*p.x)*(q.a) + (q.a*p.z + q.b*p.y - q.c*p.x)*(-q.b));
    r.z = ((-q.b*p.x - q.c*p.y - q.d*p.z)*(-q.d) + (q.a*p.x + q.c*p.z - q.d*p.y)*(-q.c) - (q.a*p.y - q.b*p.z + q.d*p.x)*(-q.b) + (q.a*p.z + q.b*p.y - q.c*p.x)*(q.a));
    return r;
};

const rectangle = new Shape();
rectangle.vertices.push(
    new Point(1,-0.5,-0.5),
    new Point(-1,0.5,-0.5),
    new Point(1,0.5,-0.5),
    new Point(-1,-0.5,0.5),
    new Point(1,-0.5,0.5),
    new Point(-1,0.5,0.5),
    new Point(1,0.5,0.5),
    new Point(-1,-0.5,-0.5)
);

const rotatedShape = new Shape();

const q1 = new Quaternion(vector, angle);

rotatedShape.vertices = rectangle.vertices.map(vertex => rotate(q1, vertex));

for(let i = 0; i < rotatedShape.vertices.length; i++){

    if(Math.abs(rotatedShape.vertices[i].x) < 0.001){
        rotatedShape.vertices[i].x = 0;
    }

    if(Math.abs(rotatedShape.vertices[i].y) < 0.001){
        rotatedShape.vertices[i].y = 0;
    }

    if(Math.abs(rotatedShape.vertices[i].z) < 0.001){
        rotatedShape.vertices[i].z = 0;
    }
}

Object.values(rotatedShape.vertices).forEach(point => point.print());