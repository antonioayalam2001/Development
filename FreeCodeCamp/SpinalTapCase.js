function spinalCase(str) {
    let regex = /\s+|_+/gi
    let regex2 = /([a-z])([A-Z])/g
    let str2
    str2 = str.replace(/([a-z])([A-Z])/g, "$1 $2");
    return str2.replace(regex,'-').toLowerCase();
}

spinalCase('This Is_Spinal Tap');
spinalCase('thisIsSpinalTap');


