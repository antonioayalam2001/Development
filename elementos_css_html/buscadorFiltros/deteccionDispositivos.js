const d = document
const n = navigator
const ua = n.userAgent

export default function userDeviceInfo(id) {
    let fragment = d.getElementById(id)
    console.log(ua)
    /*Mozilla/5.0 (iPad; CPU OS 13_3 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) CriOS/87.0.4280.77 Mobile/15E148 Safari/604.1*/
    const isMobile = {
        android : ()=>{return ua.match(/android/i)},
        ios : ()=>{return ua.match(/iphone|ipad|ipod/i)},
        windows : ()=>{return ua.match(/windows phone/ig)},
        any : function () {
            return this.ios()||this.windows()||this.android()
        }
    }
    const isDesktop = {
        linux : ()=>{return ua.match(/linux/i)},
        windows : ()=>{return ua.match(/windows/i)},
        macOS : ()=>{return ua.match(/mac os/ig)},
        any : function () {
            return this.linux()||this.windows()||this.macOS()
        }
    }
    const isBrowser = {
        chrome : ()=>{return ua.match(/chrome/i)},
        mozilla : ()=>{return ua.match(/mozilla firefox/i)},
        safari : ()=>{return ua.match(/safari/ig)},
        any : function () {
            return this.linux()||this.windows()||this.macOS()
        }
    }

    fragment.innerHTML = `
        <h1>Bienvenido tu userAgent es : ${ua}</h1>
        <h3>y estas desde un navegador ${isMobile.any() ? isMobile.any() : isDesktop.any()}</h3>
    `


}