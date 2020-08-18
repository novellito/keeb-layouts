# Iris Keyboard

My configuration for the [Iris v4](https://keeb.io/collections/split-keyboard-parts/products/iris-keyboard-split-ergonomic-keyboard) by [keeb.io](https://keeb.io/)

In order to build this firmware, I suggest you first get [setup](https://docs.qmk.fm/#/newbs_getting_started).

Once you do that here are the steps for building the firmware: 

1. Open up your `qmk_firmware` folder
2. Navigate to `/keyboards/keebio/iris/keymaps`
3. In the keymaps folder create a new folder based on your github username
4. Now in that new folder with your username copy the contents of this repository
5. Either run `qmk compile` (assuming you're setup) or run `qmk compile -kb keebio/iris/rev4 -km YOUR_GITHUB_NAME`
6. This hex file should be saved in the `.build` directory (if you don't see this folder, you may have to enable hidden files - In MacOS you can do this by opening Finder and pressing `cmd+shift+.`
