const d = document
export default function winner(button,selectors) {
    let trigger = d.querySelector(button)
    trigger.addEventListener('click',()=>{
        let array = []
        d.querySelectorAll('li.player').forEach(li=>{
            array.push(li.innerHTML)
        })

        let number = Math.round((Math.random()* (array.length))-1)
        alert(array[number])
    })
}