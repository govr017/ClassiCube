﻿using System;
using System.Collections.Generic;
using ClassicalSharp;

namespace Launcher2 {

	public partial class LauncherTableWidget : LauncherWidget {

		NameComparer nameComp = new NameComparer();
		PlayersComparer playerComp = new PlayersComparer();
		public bool DraggingWidth = false;
		
		void HandleOnClick( int mouseX, int mouseY ) {
			if( mouseX >= Window.Width - 10 ) {
				ScrollbarClick( mouseY ); return;
			}
			
			if( mouseY >= HeaderStartY && mouseY < HeaderEndY ) {			
				if( mouseX < ColumnWidths[0] - 10 ) {
					nameComp.Invert = !nameComp.Invert;
					Array.Sort( usedEntries, 0, Count, nameComp );
					Array.Sort( entries, 0, entries.Length, nameComp );
					NeedRedraw();
				} else if( mouseX > ColumnWidths[0] + 10 ) {
					playerComp.Invert = !playerComp.Invert;
					Array.Sort( usedEntries, 0, Count, playerComp );
					Array.Sort( entries, 0, entries.Length, playerComp );
					NeedRedraw();
				} else {
					DraggingWidth = true;
				}
			} else {
				for( int i = 0; i < Count; i++ ) {
					TableEntry entry = usedEntries[i];
					if( mouseY >= entry.Y && mouseY < entry.Y + entry.Height ) {
						SelectedChanged( entry.Hash );
						break;
					}
				}
			}
		}
		
		public void MouseMove( int deltaX, int deltaY ) {
			if( DraggingWidth ) {
				ColumnWidths[0] += deltaX;
				Utils.Clamp( ref ColumnWidths[0], 20, Window.Width - 20 );
				NeedRedraw();
			}
		}
		
		
		void ScrollbarClick( int mouseY ) {
			mouseY -= Y;
			float scale = (Window.Height - 10) / (float)Count;
			
			int currentIndex = (int)(mouseY / scale);
			CurrentIndex = currentIndex;
			NeedRedraw();
		}
	}
}
