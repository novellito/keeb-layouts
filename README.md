# Keyboard layouts

My qmk configurations for the following keyboards

- [Iris v4](https://keeb.io/collections/split-keyboard-parts/products/iris-keyboard-split-ergonomic-keyboard)
- [Tofu65](https://kbdfans.com/collections/diy-kit/products/tofu65-custom-mechanical-keyboard-diy-kit)
- [D65](https://kbdfans.com/products/icd65-mechanical-keyboard-kit)
- [Discipline 65](https://www.cftkb.com/shop/discipline)

In order to build the firmware, I suggest you first get [setup](https://docs.qmk.fm/#/newbs_getting_started).

Once you do that here are the steps for building the firmware:

1. Open up your `qmk_firmware` folder
1. Navigate to `/keyboards/keebio/iris/keymaps` (or whatever keyboard you're using)
1. In the keymaps folder create a new folder based on your github username
1. Now in that new folder with your username copy the contents of this repository
1. Either run `qmk compile` (assuming you're setup) or run `qmk compile -kb keebio/iris/rev4 -km YOUR_GITHUB_NAME`
1. This hex file should be saved in the `.build` directory (if you don't see this folder, you may have to enable hidden files - In MacOS you can do this by opening Finder and pressing `cmd+shift+.`
1. For Macs - Update the keyboard system preferences modifier keys to swap the option & command keys
