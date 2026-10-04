// SVG GUI (default) CSS style

const char* defaultColorsCSS = R"#(
svg.window  /* :root */
{
  --dark: #101010;  /* toolbar */
  --window: #303030;  /* menu, dialog */
  --light: #505050;  /* separator */
  --base: #202020;  /* list, inputbox */
  --button: #333333;  /* pushbuttons sit on the popup surface (--dark), so they stay close to it */
  --button-radius: 8;
  --hovered: #32809C;
  /* hover tints an item's own text/icon rather than filling the row behind it */
  --hovered-text: #2EA3CF;
  --hovered-icon: #2EA3CF;
  --pressed: #32809C;
  /* pressed tints too, a step brighter than hover so the click still reads */
  --pressed-text: #8FD9F2;
  --pressed-icon: #8FD9F2;
  --checked: #2EA3CF;  /* same as --title: an active control reads like an active icon */
  --title: #2EA3CF;
  --text: #F2F2F2;
  --text-weak: #A0A0A0;
  --text-bg: #000000;
  --icon: #CDCDCD;
  --icon-disabled: #808080;
  --canvas: #333333;  /* area around page - also used by ScribbleArea::BACKGROUND_COLOR */
  --panel-outline: #ACACAC;
  --panel-outline-width: 1;
  --on-dark-surface: #202020;  /* color picker: swatch ring, tab bar bg, hex input bg */
  /* rows inside a popup: no background of their own, just a rounded highlight on the popup surface */
  --popup-item-hovered: #2C2C2C;
  --popup-item-checked: #32809C;
  --popup-item-radius: 8;
  --popup-separator: #383838;
  /* document browser (tagdoclist.cpp) */
  --doclist-bg: #000000;  /* the document grid, behind the cards */
  --doclist-field: #444444;  /* search boxes and the small FABs */
  --fab-primary-icon: #CDCDCD;  /* icon on the accent-colored New Document FAB */
  --floating-bg: #2A2A2A;  /* select mode's floating bar */
  --floating-outline: #444444;
  --floating-separator: #555555;
  --floating-hovered: #444444;
  --floating-pressed: #555555;
}

/* light theme */
svg.window.light
{
  --dark: #F0F0F0;
  --window: #DDDDDD;
  --light: #CCCCCC;
  --base: #FFFFFF;
  --button: #C0C0C0;
  --hovered: #B8D8F9;
  --hovered-text: #1A7FA6;
  --hovered-icon: #1A7FA6;
  --pressed: #B8D8F9;
  --pressed-text: #0C4F68;
  --pressed-icon: #0C4F68;
  --checked: #2EA3CF;
  --title: #2EA3CF;
  --text: #000000;
  --text-weak: #606060;
  --text-bg: #F2F2F2;
  --icon: #303030;
  --icon-disabled: #A0A0A0;
  --canvas: #BBBBBB;
  --panel-outline: #A0A0A0;
  --panel-outline-width: 1;
  --popup-item-hovered: #E4E4E4;
  --popup-item-checked: #B8D8F9;
  --popup-separator: #CCCCCC;
  --doclist-bg: #E6E6E6;  /* not white: blank pages are white cards */
  --doclist-field: #FFFFFF;
  --fab-primary-icon: #FFFFFF;
  --floating-bg: #FFFFFF;
  --floating-outline: #CCCCCC;
  --floating-separator: #CCCCCC;
  --floating-hovered: #E4E4E4;
  --floating-pressed: #D0D0D0;
}
)#";

const char* defaultStyleCSS = R"#(
.menu { fill: var(--light); }
.menuitem { fill: var(--window); }
/* Hover/press keep the resting background and tint the row's own title and icon instead.
   These have to be *child* selectors, not descendant ones: a submenu is a child widget of the row
   that opens it and that row stays hovered/pressed the whole time the submenu is up, so a
   descendant selector would tint every row of the submenu along with its parent. Matching the
   exact depth of #menuitem-standard (menuitem > g > title | g > .menu-icon-container > .icon)
   keeps each row's state strictly its own, at any nesting depth. */
.menuitem.hovered { fill: var(--window); }
.menuitem.hovered > g > .title { fill: var(--hovered-text); }
.menuitem.hovered > g > .icon { fill: var(--hovered-icon); color: var(--hovered-icon); }
.menuitem.hovered > g > g > .icon { fill: var(--hovered-icon); color: var(--hovered-icon); }
.menuitem.checked { fill: var(--checked); }
.cbmenuitem.checked { fill: var(--window); }
.cbmenuitem.hovered { fill: var(--window); }
.menuitem.pressed { fill: var(--window); }
.menuitem.pressed > g > .title { fill: var(--pressed-text); }
.menuitem.pressed > g > .icon { fill: var(--pressed-icon); color: var(--pressed-icon); }
.menuitem.pressed > g > g > .icon { fill: var(--pressed-icon); color: var(--pressed-icon); }
/* a disabled row never tints - listed after the states above, which it ties with on specificity */
.menuitem.disabled { fill: var(--light); }
.menuitem.disabled > g > .title { fill: var(--icon-disabled); }
.menuitem.disabled > g > .icon { fill: var(--icon-disabled); color: var(--icon-disabled); }
.menuitem.disabled > g > g > .icon { fill: var(--icon-disabled); color: var(--icon-disabled); }

/* icon slot collapses unless the item actually has an icon, so titles without one start at the left edge;
   CSS outranks the display attribute (CSSSrc > XMLSrc), so this can't be done with setVisible() */
.menu-icon-container { display: none; }
.has-icon .menu-icon-container { display: block; }
.no-icon-menu .menu-icon-container { display: none; }

.list { fill: var(--base); }
.listitem { fill: var(--base); }
.listitem.pressed { fill: var(--base); }
.listitem.pressed text { fill: var(--pressed-text); }
.listitem.pressed .icon { fill: var(--pressed-icon); color: var(--pressed-icon); }

/* stroked paths in icons use stroke="currentColor" for now */
.icon { fill: var(--icon); color: var(--icon); }
.disabled .icon { fill: var(--icon-disabled); color: var(--icon-disabled); }
.toolbutton.disabled > g > .title { fill: var(--icon-disabled); }

/* set default font-size at top-level instead of every <text> */
.window { font-size: 15; }

text { fill: var(--text); }
text.window-title { fill: var(--title); font-size: 18; margin: 15px 0; }  /* link */
text.weak { fill: var(--text-weak); }
text.negative { fill: var(--text-bg); }  /* for inverted background - light in this case */
text.disabled { fill: var(--light); }

/* TODO: combine toolbutton and menuitem styles */
.toolbar { fill: var(--dark); }
.toolbar.graybar { fill: var(--light); }
/* toolbars carry the same outline as a popup, so a bar reads as its own surface against the canvas */
.toolbar-bg { stroke: var(--panel-outline); stroke-width: var(--panel-outline-width); }
/* rect.background below asks for crispEdges, which would leave the rounded corners jagged; naming both
   of the rect's classes here outranks it (rules are applied by CSS specificity) */
.toolbar-bg.background { shape-rendering: auto; }
.toolbar.statusbar .toolbar-bg { fill-opacity: 0.75; stroke-opacity: 0.75; }
/* round color/thickness swatches (pen options row): the mockup rings each swatch in the
   canvas color so that a black or white one still reads as a circle on the dark toolbar */
.swatch-btn .btn-color { stroke: var(--canvas); stroke-width: 2; }
.toolbutton { fill: none; }
/* hovering a toolbutton tints its icon instead of filling the whole cell behind it; child selectors
   for the same reason as the menu rows above - a popup opened by this button is a child of it */
.toolbutton.hovered { fill: none; }
.toolbutton.hovered > g > .icon { fill: var(--hovered-icon); color: var(--hovered-icon); }
.toolbutton.hovered > g > .title { fill: var(--hovered-text); }
.toolbutton.pressed { fill: none; }
.toolbutton.pressed > g > .icon { fill: var(--pressed-icon); color: var(--pressed-icon); }
.toolbutton.pressed > g > .title { fill: var(--pressed-text); }
.toolbutton.checked > g > .icon { fill: var(--title); color: var(--title); }  /* highlight ... was #0000C0 */

.toolbutton.checked.once > g > .icon { fill: var(--title); }  /* non-sticky; between pressed and checked */

/* the swatch prototypes (pen thickness, eraser radius) put .icon directly in the button instead of in
   the icon/title row the toolbutton prototype uses, so the > g > rules above never matched them and a
   selected thickness stayed gray.  Only `color` is set, never `fill`: these icons are strokes with
   fill="none", and CSS outranks presentation attributes here, so filling them would blot out the
   color swatch's selection ring. */
.swatch-btn.hovered > .icon { color: var(--hovered-icon); }
.swatch-btn.pressed > .icon { color: var(--pressed-icon); }
.swatch-btn.checked > .icon { color: var(--title); }
/* same omission in the roomier (non-compact) pen toolbar, where the thickness preset is a framed
   preview rather than a toolbutton: its frame is the only part drawn in the icon color */
.previewbtn.checked { color: var(--title); }
/* theme gallery tile (ThemeDialog): a tile is a picture of a page and has no .icon for the rules
   above to tint, so the selected one is ringed in the active-icon color instead.  Hidden rather than
   recolored when unchecked - an always-drawn ring in the panel color reads as a border on the page. */
.themetile .theme-sel { display: none; }
.themetile.checked .theme-sel { display: block; stroke: var(--checked); }

.arrowpopup { fill: var(--dark); }
.arrowpopup-bg { stroke: var(--panel-outline); stroke-width: var(--panel-outline-width); }
/* menu rows hosted in a popup (see ArrowPopup::addItem) sit directly on the popup surface: no per-row
   background, just a rounded highlight when hovered/checked, matching the color and help popups */
.arrowpopup .menuitem { fill: none; }
.arrowpopup .menuitem-bg { border-radius: var(--popup-item-radius); }
.arrowpopup .menuitem.hovered { fill: none; }
.arrowpopup .menuitem.pressed { fill: none; }
.arrowpopup .menuitem.checked { fill: var(--popup-item-checked); }
.arrowpopup .cbmenuitem.checked { fill: none; }
.arrowpopup .menuitem.disabled { fill: none; }
.arrowpopup .separator { fill: var(--popup-separator); }
/* a menu item carries its own inset because a Menu has no content padding of its own; inside a popup
   that inset would stack on the popup's padding, leaving items indented further than everything else.
   Only the outer (left) inset is dropped - the gap between an icon and its title is kept. */
.arrowpopup .menuitem .title { margin: 0 8 0 0; }
.arrowpopup .menuitem.has-icon .title { margin: 0 8; }
.arrowpopup .menuitem.has-icon .menu-icon-container { margin: 0; }
text.arrowpopup-title { fill: var(--text); font-size: 15; font-weight: bold; }
text.arrowpopup-desc { fill: var(--text-weak); font-size: 13; }

/* centered popup dialogs (unsaved changes, preferences, ...): the arrow popup's surface without the
   arrow - same fill, outline and corner rounding. Padding is applied by PopupDialog, not here, so
   that there is a single place to tweak it (see widgets.cpp). The surface fill is set next to the
   .dialog rule below, which would otherwise override it. */
.dialogpopup-bg { stroke: var(--panel-outline); stroke-width: var(--panel-outline-width);
    shape-rendering: auto; }  /* the rounded corners need antialiasing, unlike a plain .background */
/* margin must be zeroed here: text.window-title above sets one, and CSS outranks the margin
   attribute PopupDialog would set on the node; the gap below the title is PopupDialog::TITLE_GAP,
   applied to the body container instead */
text.dialogpopup-title { fill: var(--text); font-size: 17; font-weight: bold; margin: 0; }

.tooltip { fill: #FFFFCF; font-size: 13; }
.tooltip text { fill: #000000; }
.tooltip .alttext { font-size: 11; font-style: italic; }

.separator { fill: var(--light); }  /* toolbar (and menu?) separator */
.graybar .separator { fill: #808080; }
.statusbar .separator { fill: #808080; }

.statusbar { font-size: 24; }  /* to go with 50% scaling hack */
.statusbar .tooltip { font-size: 24; }

/* items offered on the blank pane of a split view: no resting background, hover/press feedback only */
.split-placeholder .menuitem { fill: none; }
.split-placeholder .menuitem.hovered { fill: none; }
.split-placeholder .menuitem.pressed { fill: none; }

.warning { fill: #FFFF00; }
.warning text { fill: #000000; }

.pushbutton { fill: var(--button); }
/* rounded like everything else on a popup surface; shape-rendering because rect.background below
   asks for crispEdges, which would leave the corners jagged */
.pushbtn-bg { border-radius: var(--button-radius); shape-rendering: auto; }
.pushbutton.pressed { fill: var(--pressed); }
.pushbutton.disabled { fill: #222222; }  /* below --button, which is now dark itself */
.pushbutton.checked { fill: var(--checked); }

.button-container .pushbutton { margin: 0 4; }

/* for color and width preview buttons with stroked borders */
.previewbtn { color: #808080; }
.previewbtn.hovered { color: var(--hovered-icon); }
.previewbtn.pressed { color: var(--pressed-icon); }

/* combobox, textbox, spinbox */
.inputbox { fill: var(--base); }
.comboitem { fill: var(--base); }  /* #181818 */
.comboitem.hovered { fill: var(--base); }
.comboitem.hovered text { fill: var(--hovered-text); }
.comboitem.pressed { fill: var(--base); }
.comboitem.pressed text { fill: var(--pressed-text); }
.inputbox.disabled text { fill: var(--light); }
.disabled .inputbox text { fill: var(--light); }

.checkbox { color: var(--icon); }
.checkmark { color: var(--title); }  /* active control = active icon color */
.checkbox .checkmark { display: none; }
.checkbox.checked .checkmark { display: block; }
.cbmenuitem.checked .checkmark { display: block; }
/*.checked .checkbox .checkmark { display: block; }*/

.slider-handle-outer { fill: grey; }
.slider-handle-inner { fill: black; }
/* the ruling region panel (MainWindow::buildRegionPanel): the spacing slider is the color picker's
   rounded bar and caret, the caret's gap painted in the panel color; and the Background checkbox */
.region-panel .slider-bg { fill: #4A4A4A; stroke: none; }
.region-panel .slider-caret { fill: #FFFFFF; stroke: none; }
.region-panel .slider-caret-gap { fill: var(--dark); stroke: none; }
.region-panel .region-check-tick { stroke: var(--dark); }

/* color picker: R/G/B/H/S/V/A gradient sliders (colorwidgets.cpp) */
.color-slider-thumb-outer { fill: var(--dark); }
.color-slider-label { fill: var(--text-weak); }
.color-popup-title { fill: var(--text); font-size: 18; font-weight: bold; }
.tabbar-bg { fill: var(--on-dark-surface); }
.tabbar-btn .title { fill: var(--icon); }
.tabbar-btn.checked .title { fill: var(--title); font-weight: bold; }
.colorbtn-ring { fill: var(--on-dark-surface); }
.colorbox_text .inputbox-bg { fill: var(--on-dark-surface); }

.scroll-handle { fill: var(--title); }

.inputbox-bg { stroke: var(--base); stroke-width: 2; }
/* previously we used .focused .inputbox-bg, but this created an issue w/ widgets inside a scroll widget */
.inputbox.focused .inputbox-bg { stroke: var(--icon); }
.text-cursor { fill: var(--icon); }
.cursor-handle { fill: var(--title); }
tspan.text-selection { fill: var(--text-bg); }
tspan.weak { fill: var(--text-weak); }
.text-selection-bg { fill: var(--text); }
/* margin of .textbox-container must match stroke-width of .inputbox-bg */
.textbox-container { margin: 0 2; }

.hrule { fill: var(--light); }
.spacer { fill: none; }  /* blank gap where a rule would otherwise separate sections */
.hrule.title { fill: var(--title); }
.hrule.title.inactive { fill: #D8D8D8; }

/* display node isn't in style, so SVG attribute just gets overwritten and can't be restored! */
.window-overlay { fill: black; fill-opacity: 0.5; display: none; }
.disabled .window-overlay { display: block; }

.dialog { fill: var(--window); }  /* .dialog-bg doesn't work for scroll view inside dialog! */
.dialogpopup { fill: var(--dark); }  /* popup dialogs sit on the arrow popup surface instead */
.panel-header { fill: var(--window); }
.panel-header .toolbar { fill: var(--window); }

.splitter { fill: var(--dark); }

rect.background { shape-rendering: crispEdges; }
/*rect.inputbox-bg { shape-rendering: crispEdges; }  -- problem because this applies to stroke too */

.menu, .dialog { box-shadow: 0px 0px 10px 0px rgba(0,0,0,0.5); }
/* the selection popup is a rounded floating panel (12*floatUIScale corners, mainwindow.cpp): its shadow
   follows those corners and falls below it, pulled in by the spread so it does not ring the top edge */
.menu.sel-popup { box-shadow: 0px 3px 8px -2px rgba(0,0,0,0.45); border-radius: 6; }
/*.menu, .dialog { box-shadow: 0px 0px 40px 0px rgba(0,0,0,0.40); }*/ /* like android, but doesn't look great on computer */
/*.menu, .dialog { box-shadow: 6px 6px 4px -4px rgba(0,0,0,0.375); }*/ /* offset shadow like Windows */

/* tag sidebar document browser (tagdoclist.cpp) - the redesign's two typefaces: Raleway for the
   "Write" wordmark, Satoshi for everything else. Set once on the window root since font-family
   inherits, rather than repeating it on every text node. */
.tagdoclist { font-family: satoshi; }
.tagdoclist .doclist-title { font-family: raleway; font-size: 32; fill: var(--text); }
.tagdoclist .sidebar { fill: var(--dark); }
.tagdoclist .doclist-content { fill: var(--doclist-bg); }
/* the sidebar's own bottom toolbars (undo bar, tag actions) sit directly on the sidebar's own dark
   background, not on a separate toolbar surface - the default .toolbar fill and .toolbar-bg outline
   read as a stray box around them, so both are switched off within this window only */
.tagdoclist .toolbar { fill: none; }
.tagdoclist .toolbar-bg { stroke: none; fill: none; }
/* the search boxes' rounded fill *is* the TextEdit's own background (sized to the text, not a
   separate larger rect behind it) - rounded always, with a rounded focus ring instead of the
   default square one */
.tagdoclist .inputbox { fill: none; }
.tagdoclist .inputbox-bg { fill: var(--doclist-field); stroke: none; border-radius: 10; }
.tagdoclist .inputbox.focused .inputbox-bg { stroke: var(--icon); stroke-width: 2; }
/* document cards carry their own thumbnail/paper color; the default .listitem fill behind them just
   reads as an unwanted card background */
.tagdoclist .doc-cell { fill: none; }
/* the FABs (TagDocList::createFab()): the small ones sit on the grid like the search boxes do */
.tagdoclist .fab-bg { fill: var(--doclist-field); }
.tagdoclist .fab-primary .fab-bg { fill: #2EA3CF; }
.tagdoclist .fab-primary .icon { fill: var(--fab-primary-icon); color: var(--fab-primary-icon); }
/* select mode (TagDocList::setSelectMode()): a ring and a check badge on each document; the badge is
   an empty circle until the cell is checked.  The bar replacing the FABs is one rounded container
   around FAB-sized buttons that light up only when hovered or pressed. */
.tagdoclist .select-ring { display: none; fill: none; stroke: #2EA3CF; stroke-width: 3; }
.tagdoclist .doc-cell.checked .select-ring { display: block; }
.tagdoclist .select-badge-bg { fill: #000000; fill-opacity: 0.45; stroke: #FFFFFF; stroke-width: 1.5; }
.tagdoclist .doc-cell.checked .select-badge-bg { fill: #2EA3CF; fill-opacity: 1; stroke: #2EA3CF; }
.tagdoclist .select-check { display: none; }
.tagdoclist .doc-cell.checked .select-check { display: block; fill: #FFFFFF; color: #FFFFFF; }
.tagdoclist .selectbar-bg { fill: var(--floating-bg); stroke: var(--floating-outline); stroke-width: 1; }
.tagdoclist .selectbar-count { fill: var(--text); font-size: 15; }
.tagdoclist .selectbar-sep { fill: var(--floating-separator); }
.tagdoclist .selectbar-btn-bg { fill: none; }
.tagdoclist .selectbar-btn.hovered .selectbar-btn-bg { fill: var(--floating-hovered); }
.tagdoclist .selectbar-btn.pressed .selectbar-btn-bg { fill: var(--floating-pressed); }
.tagdoclist .selectbar-btn.disabled .icon { fill: var(--icon-disabled); color: var(--icon-disabled); }
.tagdoclist .selectbar-delete .icon { fill: #E5534B; color: #E5534B; }
.tagdoclist .selectbar-delete.disabled .icon { fill: var(--icon-disabled); color: var(--icon-disabled); }
.tag-row { fill: none; }
.tag-row > g > .title { fill: var(--text); }
/* hovering a tag colors its label/icon only, like a plain toolbutton (All Documents) - it must not
   light up a background rect the way a normal list item would.
   Direct-child chains (matching the existing .toolbutton.checked > g > .icon rule), not descendant
   selectors: an ArrowPopup opened from a row (see showTagMenu()) is added as a literal DOM child of
   that row for positioning, and its own .title/.icon elements are genuine descendants of
   .tag-row.checked too - a bare ".tag-row.checked .title" bled this row's checked/hovered color into
   whatever popup happened to be open on it. */
.tag-row.hovered > g > .title { fill: var(--hovered-text); }
.tag-row.hovered > g > .icon-container > .icon { fill: var(--hovered-icon); color: var(--hovered-icon); }
.tag-row.pressed > g > .title { fill: var(--pressed-text); }
.tag-row.pressed > g > .icon-container > .icon { fill: var(--pressed-icon); color: var(--pressed-icon); }
.tag-row.checked > g > .title { fill: var(--checked); }
.tag-row.checked > g > .icon-container > .icon { fill: var(--checked); color: var(--checked); }

/* general-purpose sidebar (sidebar.cpp / SIDEBAR_SPEC.md).  Colors are literals from the Penpot
   file rather than theme variables, exactly as the floating toolbar panels are: this panel is part
   of that same dark floating chrome, which does not follow the document's light/dark theme. */
.gp-sidebar { font-family: satoshi; }
/* outlined like .toolbar-bg, so the sidebar reads as the same kind of surface as the toolbar above it */
.gp-sidebar .panel-bg { fill: #101010; stroke: var(--panel-outline); stroke-width: var(--panel-outline-width); }
.gp-sidebar .field-bg { fill: #444444; stroke: none; }
.gp-sidebar .sb-view-label { fill: #CDCDCD; }
.gp-sidebar .sb-title { fill: #F2F2F2; }
.gp-sidebar .sb-sub { fill: #CDCDCD; }
.gp-sidebar .sb-preview { fill: #B1B2B5; stroke: none; }
/* rows are transparent; only their text reacts, like a tag row rather than a list item */
.gp-sidebar .sb-row, .gp-sidebar .sb-row-sizer, .gp-sidebar .sb-actions-sizer { fill: none; }
/* the pinned sidebar owns its whole column; its margins are painted as canvas surround rather than
   left showing whatever the canvas drew there before it shrank */
.gp-sidebar .sb-backfill { fill: var(--canvas); stroke: none; }
.gp-sidebar .sb-row.hovered > g > .sb-title { fill: var(--hovered-text); }
.gp-sidebar .sb-row.pressed > g > .sb-title { fill: var(--pressed-text); }
/* the current layer, per the design's blue label */
.gp-sidebar .sb-row.checked > g > .sb-title { fill: #2EA3CF; }
/* an unlocked layer still offers its lock, dimmed - the design draws the icon on locked rows only */
.gp-sidebar .sb-lock-off .icon { opacity: 0.35; }
/* the search box's rounded fill is the row's own .field-bg, so the TextEdit contributes no chrome.
   border-radius is still set because the base .inputbox.focused rule (two classes, so more specific
   than this one) puts a stroke back on while the field has focus - without a radius here that focus
   ring is drawn square around a rounded field. */
.gp-sidebar .inputbox, .gp-sidebar .inputbox-bg { fill: none; stroke: none; border-radius: 6; }
.gp-sidebar .toolbar, .gp-sidebar .toolbar-bg { fill: none; stroke: none; }
)#";

// document containing prototypes for widgets; identified by SVG class
static const char* defaultWidgetSVG = R"#(
<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">

  <defs>
    <!-- these should be <symbol>s once we move viewBox logic to SvgViewportNode -->
    <svg id="chevron-left" width="96" height="96" viewBox="0 0 96 96">
      <polygon points="57.879,18.277 32.223,47.998 57.879,77.723 63.776,72.634 42.512,47.998 63.776,23.372"/>
    </svg>

    <svg id="chevron-down" width="96" height="96" viewBox="0 0 96 96">
      <polygon points="72.628,32.223 48.002,53.488 23.366,32.223 18.278,38.121 48.002,63.777 77.722,38.121"/>
    </svg>

    <svg id="chevron-right" width="96" height="96" viewBox="0 0 96 96">
      <polygon points="32.223,23.372 53.488,47.998 32.223,72.634 38.121,77.723 63.777,47.998 38.121,18.277"/>
    </svg>
  </defs>

  <g id="menu" class="menu" display="none" position="absolute" box-anchor="fill" layout="box">
    <rect class="background menu-bg" box-anchor="fill" width="20" height="20"/>
    <g class="child-container" box-anchor="fill" layout="flex" flex-direction="column">
    </g>
  </g>

  <!-- background path is regenerated by ArrowPopup at layout time; initial size just sets a minimum -->
  <g id="arrowpopup" class="arrowpopup" display="none" position="absolute" box-anchor="fill" layout="box">
    <path class="background arrowpopup-bg" box-anchor="fill" d="M0 0 H20 V20 H0 Z"/>
    <g class="child-container" box-anchor="fill" layout="flex" flex-direction="column">
    </g>
  </g>

  <!-- thin space between menu items acts as separator, so we don't want class=background on menu item BG -->
  <g id="menuitem-standard" class="menuitem" box-anchor="fill" margin="1 0" layout="box">
    <rect class="menuitem-bg" box-anchor="hfill" width="150" height="36"/>
    <g box-anchor="left vfill" layout="flex" flex-direction="row">
      <g class="menu-icon-container" layout="box" margin="0 0 0 8">
        <use display="none" class="icon" width="23.04" height="23.04" xlink:href=""/>
      </g>
      <text class="title" margin="0 8"></text>
    </g>
  </g>

  <g id="menuitem-submenu" class="menuitem" box-anchor="fill" margin="1 0" layout="box">
    <rect class="menuitem-bg" box-anchor="hfill" width="150" height="36"/>
    <g box-anchor="fill" layout="flex" flex-direction="row">
      <g class="menu-icon-container" layout="box" margin="0 0 0 8">
        <use display="none" class="icon" width="23.04" height="23.04" xlink:href=""/>
      </g>
      <text class="title" margin="0 8"></text>
      <rect class="stretch" box-anchor="fill" fill="none" width="8" height="36"/>
      <use class="icon submenu-indicator" width="24" height="24" xlink:href="#chevron-right" />
    </g>
  </g>

  <g id="menuitem-custom" class="menuitem" box-anchor="fill" margin="1 0" layout="box">
    <rect class="menuitem-bg" box-anchor="hfill" width="150" height="36"/>
    <g class="menuitem-container" box-anchor="fill" layout="box">
    </g>
  </g>

  <g id="menu-separator" class="menu-separator" layout="box">
    <rect box-anchor="hfill" width="36" height="9"/>
    <rect class="separator" box-anchor="hfill" margin="0 4" width="26" height="6"/>
  </g>

  <g id="toolbar" class="toolbar" box-anchor="hfill" layout="box">
    <rect class="toolbar-bg background" box-anchor="fill" width="20" height="20"/>
    <g class="child-container" box-anchor="hfill" layout="flex" flex-direction="row">
    </g>
  </g>

  <g id="vert-toolbar" class="toolbar vert-toolbar" box-anchor="vfill" layout="box">
    <rect class="toolbar-bg background" box-anchor="fill" width="20" height="20"/>
    <g class="child-container" box-anchor="vfill" layout="flex" flex-direction="column">
    </g>
  </g>

  <!-- note that class=checkmark can be moved to the filling rect to color whole background when checked -->
  <g id="toolbutton" class="toolbutton" layout="box" margin="0 4">
    <rect class="background" box-anchor="hfill" width="36" height="42"/>
    <rect class="checkmark" box-anchor="bottom hfill" margin="0 2" fill="none" width="36" height="3"/>
    <g margin="0 3" box-anchor="fill" layout="flex" flex-direction="row" justify-content="center">
      <use class="icon" width="23.04" height="23.04" xlink:href="" />
      <text class="title" display="none" margin="0 9"></text>
    </g>
  </g>

  <g id="toolbar-separator" class="toolbar-separator" box-anchor="vfill" layout="box">
    <rect fill="none" box-anchor="vfill" width="16" height="36"/>
    <rect class="separator" box-anchor="vfill" margin="4 0" width="2" height="36"/>
  </g>

  <g id="vert-toolbar-separator" class="toolbar-separator" box-anchor="hfill" layout="box">
    <rect fill="none" box-anchor="hfill" width="36" height="16"/>
    <rect class="separator" box-anchor="hfill" margin="0 4" width="36" height="2"/>
  </g>

  <g id="tooltip" class="tooltip" box-anchor="fill" layout="box">
    <rect box-anchor="fill" stroke-width="0.5" stroke="#000" width="36" height="36"/>
  </g>

  <g id="pushbutton" class="pushbutton" box-anchor="fill" layout="box">
    <rect class="background pushbtn-bg" box-anchor="hfill" width="36" height="36"/>  <!-- rx="8" ry="8" -->
    <text class="title" margin="8 8"></text>
  </g>

  <g id="radiobutton" class="radiobutton checkbox">
    <rect fill="none" width="26" height="26"/>
    <circle fill="none" stroke="currentColor" stroke-width="1.5" cx="13" cy="13" r="8" />
    <circle class="checkmark" fill="currentColor" cx="13" cy="13" r="5" />
  </g>

  <g id="checkbox" class="checkbox">
    <rect fill="none" width="26" height="26"/>
    <rect x="4" y="4" fill="none" stroke="currentColor" stroke-linejoin="round" stroke-width="1.5" width="18" height="18"/>
    <g class="checkmark">
      <rect x="3.25" y="3.25" fill="currentColor" width="19.5" height="19.5"/>
      <path fill="none" stroke="white" stroke-width="12" transform="translate(3.25, 3.25) scale(0.20)" d="M15 45 L40 70 L85 25"/>
    </g>
  </g>

  <g id="textedit" class="inputbox textbox" layout="box">
    <!-- invisible rect to set minimum width -->
    <rect class="min-width-rect" width="150" height="36" fill="none"/>
    <rect class="inputbox-bg" box-anchor="fill" width="20" height="20"/>
  </g>

  <!-- non-editable textbox for combobox and spinbox -->
  <g id="textbox" class="textbox" box-anchor="fill" layout="box">
    <text box-anchor="left" margin="3 6"></text>
  </g>

  <g id="combobox" class="inputbox combobox" layout="box">
    <rect class="min-width-rect" width="150" height="36" fill="none"/>
    <rect class="inputbox-bg" box-anchor="fill" width="150" height="36"/>

    <g class="combo_content" box-anchor="fill" layout="flex" flex-direction="row" margin="0 2">
      <g class="textbox combo_text" box-anchor="fill" layout="box">
      </g>

      <g class="combo_open" box-anchor="vfill" layout="box">
        <rect fill="none" box-anchor="vfill" width="28" height="28"/>
        <use class="icon" width="28" height="28" xlink:href="#chevron-down" />
      </g>
    </g>

    <g class="combo_menu menu" display="none" position="absolute" top="100%" left="0" box-anchor="fill" layout="box">
      <!-- invisible rect to set minimum width; proper soln would be to support left=0 right=0 to stretch -->
      <rect class="combo-menu-min-width" width="150" height="36" fill="none"/>
      <rect class="background menu-bg" box-anchor="fill" width="20" height="20"/>
      <g class="child-container" box-anchor="fill" layout="flex" flex-direction="column">
        <g class="combo_proto comboitem" display="none" box-anchor="fill" layout="box">
          <rect box-anchor="hfill" width="36" height="36"/>
          <text box-anchor="left" margin="8 8">Prototype</text>
        </g>
      </g>
    </g>
  </g>

  <g id="spinbox" class="inputbox spinbox" layout="box">
    <rect class="min-width-rect" width="150" height="36" fill="none"/>
    <rect class="inputbox-bg" box-anchor="fill" width="150" height="36"/>

    <g class="spinbox_content" box-anchor="fill" layout="flex" flex-direction="row" margin="0 2">
      <g class="textbox spinbox_text" box-anchor="fill" layout="box">
      </g>

      <!-- inc/dec buttons -->
      <g class="toolbutton spinbox_dec" box-anchor="vfill" layout="box">
        <rect class="background" width="28" height="28"/>
        <use class="icon" width="28" height="28" xlink:href="#chevron-left" />
      </g>
      <g class="toolbutton spinbox_inc" box-anchor="vfill" layout="box">
        <rect class="background" width="28" height="28"/>
        <use class="icon" width="28" height="28" xlink:href="#chevron-right" />
      </g>
    </g>
  </g>

  <g id="slider" class="slider" box-anchor="hfill" layout="box">
    <rect class="min-width-rect" width="150" height="28" fill="none"/>
    <rect class="slider-bg background" box-anchor="hfill" width="200" height="28" margin="0 12"/>
    <g class="slider-handle-container" box-anchor="left">
      <!-- invisible rect to set left edge of box so slider-handle can move freely -->
      <rect width="28" height="28" fill="none"/>
      <g class="slider-handle" transform="translate(10,0)">
        <rect class="slider-handle-outer" x="-12" y="-2" width="24" height="32"/>
        <rect class="slider-handle-inner" x="-9" y="0" width="18" height="28"/>
      </g>
    </g>
  </g>

  <svg id="dialog" class="window dialog" display="none" layout="box">
    <rect class="dialog-bg background" box-anchor="fill" width="20" height="20"/>
    <g class="dialog-layout" box-anchor="fill" layout="flex" flex-direction="column">
      <text class="window-title title" box-anchor="left"></text>
      <rect class="hrule title" box-anchor="hfill" width="20" height="2"/>
      <g class="body-container" box-anchor="fill" layout="flex" flex-direction="column">
      </g>
      <g class="button-container dialog-buttons" margin="5 4" box-anchor="hfill" layout="flex" flex-direction="row">
      </g>
    </g>
  </svg>

  <!-- centered popup dialog: the arrow popup's look minus the arrow; padding and corner radius are
       applied by PopupDialog at construction (widgets.cpp), keeping them in one place -->
  <svg id="popupdialog" class="window dialog dialogpopup" display="none" layout="box">
    <rect class="dialog-bg dialogpopup-bg background" box-anchor="fill" width="20" height="20"/>
    <g class="dialog-layout" box-anchor="fill" layout="flex" flex-direction="column">
      <text class="window-title dialogpopup-title" box-anchor="left"></text>
      <g class="body-container" box-anchor="fill" layout="flex" flex-direction="column">
      </g>
      <g class="button-container dialog-buttons" box-anchor="hfill" layout="flex" flex-direction="row">
      </g>
    </g>
  </svg>

  <rect id="scroll-handle" class="scroll-handle" box-anchor="vfill" width="4" height="20" rx="2" ry="2"/>

  <g id="colorbutton" class="color_preview previewbtn">
    <rect class="min-width-rect" fill="none" width="37" height="37"/>
    <pattern id="checkerboard" x="0" y="0" width="18" height="18"
        patternUnits="userSpaceOnUse" patternContentUnits="userSpaceOnUse">
      <rect fill="black" fill-opacity="0.1" x="0" y="0" width="9" height="9"/>
      <rect fill="black" fill-opacity="0.1" x="9" y="9" width="9" height="9"/>
    </pattern>

    <circle class="colorbtn-ring" cx="18" cy="18" r="17.5" />
    <circle fill="white" cx="18" cy="18" r="13.5" />
    <circle fill="url(#checkerboard)" cx="18" cy="18" r="13.5" />
    <circle class="btn-color" fill="blue" cx="18" cy="18" r="13.5" />
  </g>

</svg>
)#";
