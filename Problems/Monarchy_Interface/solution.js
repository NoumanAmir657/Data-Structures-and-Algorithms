class Monarchy {
    constructor(name) {
        this.firstMonarch = new Person(name, undefined)
        this.currentMonarch = this.firstMonarch
        this.familyTree = {}
        this.familyMembers = []
        this.familyMembers.push(this.currentMonarch)
    }

    birth(child, parent){
        if(!this.familyTree[parent]){
            this.familyTree[parent] = []
            this.familyTree[child] = []
            const newMember = new Person(child, parent)
            this.familyTree[parent].push(newMember)
            this.familyMembers.push(newMember)
        }
        else{
            this.familyTree[child] = []
            const newMember = new Person(child, parent)
            this.familyTree[parent].push(newMember)
            this.familyMembers.push(newMember)
        }
    }

    death(name){
        // check if name is of current Monarch
        if (name === this.currentMonarch.name){
            // since monarchs have no parents alive
            // get children of monarch
            const childrens = this.familyTree[name]
            // get first child of monarch
            const successor = childrens[0]
            // get rest of the children of monarch
            let otherChildrenOfMonarch = childrens.splice(1)
            // concat rest of the children to to next successor
            for (let i = 0; i < otherChildrenOfMonarch.length; ++i){
                otherChildrenOfMonarch[i].parent = successor.name
            }
            this.familyTree[successor.name] = this.familyTree[successor.name].concat(otherChildrenOfMonarch)
            // change current monarch
            this.currentMonarch = successor
            // remove the dead person from family tree
            delete this.familyTree[name]
            // remove from family members
            this.familyMembers = this.familyMembers.filter(x => x.name !== name)
        }
        // else name is not of current monarch
        else{
            // get person object
            const deadObject = this.familyMembers.find(x => x.name === name) // Mark Object
            // get children of the dead person
            const childrens = this.familyTree[name] // empty array
            // get parent of dead
            const parentOfDead = deadObject.parent
            // get children of parentOfDead
            const c = this.familyTree[parentOfDead]

            let newC = []
            for (let i = 0; i < c.length; ++i){
                if (c[i].name === name){
                    newC = newC.concat(childrens)
                }
                else{
                    newC.push(c[i])
                }
            }
            this.familyTree[parentOfDead] = newC

            // remove from family tree
            delete this.familyTree[name]
            // remove from family members
            this.familyMembers = this.familyMembers.filter(x => x.name !== name)
        }
    }

    getOrderOfSuccession(){
        const successionOrder = []
        successionOrder.push(this.currentMonarch.name)
        this.recursiveUtil(this.currentMonarch.name, successionOrder)
        return successionOrder
    }
    recursiveUtil(nameOfPerson, successionOrder){
        const childrens = this.familyTree[nameOfPerson]
        if (childrens === undefined){return}
        for (let i = 0; i < childrens.length; ++i){
            successionOrder.push(childrens[i].name)
            this.recursiveUtil(childrens[i].name, successionOrder)
        }
    }
}

class Person {
    // takes two arguments name of person and person's parent
    constructor(name, parent){
        this.name = name
        this.parent = parent
    }
}

const m = new Monarchy('Jack')
m.birth('Catherine', 'Jack')
m.birth('Jane', 'Catherine')
m.birth('Farah', 'Jane')
m.birth('Tom', 'Jack')
m.birth('Celine', 'Jack')
m.birth('Mark', 'Catherine')
m.birth('Peter', 'Celine')
console.log(m.familyTree)
console.log(m.getOrderOfSuccession())

m.death('Jack')
console.log(m.familyTree)
console.log(m.getOrderOfSuccession())

m.death('Jane')
console.log(m.familyTree)
console.log(m.getOrderOfSuccession())

m.death('Catherine')
console.log(m.familyTree)
console.log(m.getOrderOfSuccession())

m.death('Mark')
console.log(m.familyTree)
console.log(m.getOrderOfSuccession())
