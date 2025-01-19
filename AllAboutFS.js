const fs = require("fs");
const os = require("os")

const cups = os.cpus().length;
console.log("this is the cpus length", cups)
// write fiile start  (it will rewrite all the data from starting every time we write)
//==> it is synchronous
fs.writeFileSync("test.txt", "Hey there!!... how are you")
//==> its is asynchronous
fs.writeFile("test2.txt", "hey there!!... how are you",(err)=>{
    // if(err)console.log(err)
    })
// wrtie fiile end


// read file start 
// read file it has two arguments first is the path of the file and second is the encoding 
//==> read file sync
const readresultsync = fs.readFileSync("./test.txt", "utf-8")
// console.log("readresultsync", readresultsync)

//==> read file async
fs.readFile("./test.txt", "utf-8", (err, res)=>{console.log("resultasync==> ", res)})
// read file end 


// append file (it appned the data )
fs.appendFileSync("append test", "second append");



// delete file 
// fs.unlinkSync("./test.txt")


// stat of file ( it gives all the data or details about the file)

// console.log(fs.statSync("./test2.txt"))