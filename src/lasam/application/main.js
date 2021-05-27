const { BrowserWindow, app } = require('electron')
const path = require('path')

function createWindow() {
    win = new BrowserWindow({
        width: 800,
        height: 600,
        frame: false,
        resizable: false,
        webPreferences: { nodeIntegration: true, contextIsolation: false, enableRemoteModule: true, preload: path.join(__dirname, 'preload.js') }
    });
    win.loadFile('index.html')
}

app.whenReady().then(() => {
    createWindow()
    app.on('activate', function () {
        if (BrowserWindow.getAllWindows().length === 0) createWindow()
    })
})

app.on('window-all-closed', function () {
    if (process.platform !== 'darwin') app.quit()
})